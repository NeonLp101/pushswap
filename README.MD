*This project has been created as part of the 42 curriculum by lernst, jihchoi.*

# push_swap

> Sort a stack of integers in ascending order using two stacks and a restricted
> instruction set, in as few operations as possible.

---

## Description

**push_swap** is an algorithmic project from the 42 Common Core. The goal is to
sort a list of integers placed on **stack `a`**, using a second auxiliary
**stack `b`** and a limited set of operations, while emitting the *smallest
practical* sequence of those operations to standard output.

The real lesson of the project is **algorithmic complexity made concrete**: the
same data can be sorted in a dozen operations or in tens of thousands, depending
entirely on the strategy chosen. To make that trade-off explicit, this
implementation ships **four distinct sorting strategies** and a runtime selector
that picks the right one based on how disordered the input actually is.

The allowed operations are:

| Op | Effect |
|------|--------|
| `sa` / `sb` / `ss` | swap top two of `a` / `b` / both |
| `pa` / `pb` | push top of the other stack onto `a` / `b` |
| `ra` / `rb` / `rr` | rotate `a` / `b` / both up (first → last) |
| `rra` / `rrb` / `rrr` | reverse-rotate `a` / `b` / both down (last → first) |

---

## Instructions

### Build

```sh
make          # builds push_swap 
make clean    # removes object files
make fclean   # removes objects + binaries
make re       # fclean + all
```

The Makefile compiles with `-Wall -Wextra -Werror` using `cc`, builds the bundled
`libft` via its own Makefile first, and does **not** relink unnecessarily.
No global variables are used.

### Run

```sh
./push_swap <list of integers>
```

The first argument is the **top** of the stack. The program prints one operation
per line to **stdout**. If no arguments are given, it prints nothing and returns
the prompt. On invalid input (non-integers, values outside `int` range,
duplicates) it prints `Error\n` to **stderr**.

### Strategy selector (optional)

| Flag | Strategy | Complexity (in operations) |
|------|----------|----------------------------|
| `--simple`   | Selection sort        | O(n²) |
| `--medium`   | Chunk sort            | O(n√n) |
| `--complex`  | Binary radix sort     | O(n log n) |
| `--adaptive` | Disorder-driven dispatch (**default**) | per-regime, see below |

### Benchmark mode

`--bench` prints metrics to **stderr** after sorting, leaving the operation
stream clean on stdout so it can still be piped to a checker:

```sh
$> ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker $ARG
OK
$> cat bench.txt
[bench] disorder:   40.00%
[bench] strategy:   Adaptive / O(n√n)
[bench] total_ops:  13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0
```
In zsh use it like this:
```sh
$> ARG=(4 67 3 87 23); ./push_swap --bench $ARG 2>bench.txt | ./checker_linux $ARG
OR
$> ARG=("${(@f)$(shuf -i 1-100000 -n 500)}"); ./push_swap $ARG | ./checker_linux $ARG
```

Reported fields: computed disorder (`%`, two decimals), selected strategy and its
complexity class, total operation count, and a per-type breakdown of all eleven
operations.

### Examples

```sh
$> ./push_swap 2 1 3 6 5 8
$> ./push_swap --simple 5 4 3 2 1
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
$> ./push_swap --adaptive 0 one 2 3     # -> Error (non-integer)
$> ./push_swap --simple 3 2 3           # -> Error (duplicate)
```

---

## Data structure

Both stacks are stored as a **circular doubly-linked list with a sentinel node**.
The sentinel removes edge-case branching at the head/tail, makes `ra`/`rra` (and
the `b` equivalents) O(1) pointer re-links rather than list traversals, and lets
`pa`/`pb` splice a node across stacks without reallocation. This keeps every
elementary operation O(1), so the operation count of a strategy maps directly to
its asymptotic class.

The benchmark counters live in a single `t_count` struct that is allocated on
`main`'s frame and reached through a pointer stored on **both stacks' sentinels**.
This gives every operation a shared place to tally itself **without using any
global variable**, satisfying the subject's hard constraint.

---

## Algorithms — explanation and justification

All complexity statements below are in the **push_swap operation model**: the cost
is the number of emitted operations, not the cost of a classical array sort. Since
each operation is an O(1) pointer move on the linked stacks, these bounds describe
real runtime as well.

### 1. Simple — selection sort · O(n²)

Repeatedly find the minimum remaining in `a`, rotate it to the top (choosing
`ra` vs `rra` by whichever distance is shorter), then `pb`. After all elements are
on `b` in descending order, `pa` everything back. Each of the n selections costs up
to O(n) rotations → **O(n²) operations**, **O(1)** extra space.
Justification: it is the honest baseline that makes the cost of *not* thinking
about complexity visible, and it is genuinely the fastest option when only a
handful of elements are out of place (see the adaptive rationale).

### 2. Medium — chunk sort · O(n√n)

Values are first **rank-normalized** to `0..n-1` so chunk boundaries are exact and
independent of the raw value range. The range is split into roughly **√n chunks**.
The algorithm pushes elements from `a` to `b` chunk by chunk (rotating `a` to bring
the next in-range element to the top), then pushes them back from `b` into sorted
position. Each element travels O(√n) on average → **O(n√n) operations**, **O(n)**
space for the rank table. Justification: it is the textbook middle gear —
materially better than O(n²) on partially-shuffled input without the fixed
overhead of a full radix pass.

### 3. Complex — binary radix sort · O(n log n)

Values are rank-normalized to `0..n-1`, so the largest value needs
`b = ⌈log₂ n⌉` bits. For each bit from least- to most-significant, every element is
inspected once: if the current bit is `0` it is sent to `b` with `pb`, otherwise it
is kept with `ra`. After each pass, `b` is emptied back onto `a`. With **b passes
of O(n) operations each**, the total is **O(n·log n) operations**, **O(n)** space
for ranks. Justification: radix is non-comparative and stable, has no worst-case
blowup, and is the right tool for fully random input — which is exactly where the
operation budget is tightest.

### 4. Adaptive — disorder-driven dispatch (default)

The **disorder metric** is the value the subject defines: count every pair
`(i, j)` with `i < j` where `a[i] > a[j]` (an *inversion*), and normalize by the
total number of pairs:

```
disorder = inversions / (n·(n-1)/2)
```

This is exactly the **normalized Kendall-τ distance from the sorted permutation**:
`0` means already sorted, `1` means fully reversed. It is measured **once, before
any move**. The adaptive strategy then dispatches:

| Measured disorder | Method used | Complexity guaranteed |
|-------------------|-------------|-----------------------|
| `disorder < 0.2`        | Simple  | O(n²) |
| `0.2 ≤ disorder < 0.5`  | Medium  | O(n√n) |
| `disorder ≥ 0.5`        | Complex | O(n log n) |

**Threshold rationale.** Big-O describes the worst case, but the *number of
inversions is the actual work to be undone.* When `disorder < 0.2` the stack is
nearly sorted, so few inversions exist; selection/insertion-style work touches very
little and finishes in far fewer real operations than radix, which always processes
every bit of every element regardless of how sorted the input already is — paying a
fixed overhead that dominates on near-sorted data. As disorder climbs into the
mid-range, the inversion count grows and the chunk method's √n locality starts to
pay off. Past `0.5` the input is effectively random, the inversion count is near its
maximum, and radix's flat O(n log n) ceiling is the safest bet for staying inside
the operation budget. The cutoffs `0.2` / `0.5` are the points where, in our
benchmarking, each method's measured operation count overtook the next.

---

## Performance

Measured with the bundled checker over random inputs (excellent-tier targets shown):

| Input size | Target (excellent) | Typical result (adaptive) |
|------------|--------------------|---------------------------|
| 100 numbers | < 700 ops  | within budget |
| 500 numbers | < 5500 ops | within budget |

Reproduce:

```sh
ARG="$(seq 1 500 | shuf | tr '\n' ' ')"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG      # -> OK
```

---

## Contributions

> Adjust this section to reflect the real split before submission — it must
> clearly document both learners' contributions.

| Area | lernst | jihchoi |
|------|:------:|:-------:|
| Stack structure & elementary operations | ● | ● |
| Parsing, validation & error handling | ● | ● |
| Simple (selection) strategy | ● | |
| Medium (chunk) strategy | | ● |
| Complex (radix) strategy | ● | ● |
| Disorder metric & adaptive dispatch | | ● |
| `--bench` instrumentation | ● | |
| Testing, benchmarking & README | ● | ● |

---

## Resources

Sorting & the radix approach in the push_swap context:
- Push_swap radix-sort tutorial — Nerd For Tech / Medium: <https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e>
- Insertion-in-chunks walkthrough — Jamie Dawson / Medium: <https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a>

Disorder metric (theory behind our inversion count):
- Inversion (discrete mathematics) — Wikipedia: <https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)>
- Kendall tau distance — Wikipedia: <https://en.wikipedia.org/wiki/Kendall_tau_distance>
- Mannila, *Measures of presortedness and optimal sorting algorithms* (1984), LNCS 172 — the formal basis for choosing a sort by how presorted the input is.

General sorting background:
- Knuth, *The Art of Computer Programming, Vol. 3: Sorting and Searching* — Big-O and radix sort foundations.

### How AI was used

AI (Claude) was used as a **sounding board and reviewer**, in line with the
project's AI guidelines — never as a code generator we couldn't explain:
- discussing the trade-offs between selection / chunk / radix and where each wins;
- rubber-duck debugging (e.g. a Makefile wildcard causing duplicate linking, debug
  `write` calls leaking onto stdout, flag parsing consuming numeric arguments);
- drafting and structuring this README.

Every algorithm was designed, implemented, tested, and peer-reviewed by both
learners.