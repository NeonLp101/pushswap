/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:06:38 by jihchoi           #+#    #+#             */
/*   Updated: 2026/06/16 17:53:19 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
};

typedef struct s_count
{
	int	ops[11];
}	t_count;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	t_count			*cnt;
}	t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_args
{
	t_strategy	requested;
	t_strategy	resolved;
	double		disorder;
	int			bench;
}	t_args;

double		compute_disorder(t_stack *a);
int			parse_flags(int argc, char **argv, t_args *opts);
void		run_strategy(t_stack *a, t_stack *b, t_strategy s);
t_strategy	pick_adaptive(double disorder);

t_stack		*stack_new(void);
void		stack_clear(t_stack *s);
t_stack		*node_new(int value);
void		add_back(t_stack *s, t_stack *node);
void		add_front(t_stack *s, t_stack *node);
void		print_stack(t_stack *s);

/* primitives (no write) */
void		op_swap(t_stack *s);
void		op_rotate(t_stack *s);
void		op_reverse_rotate(t_stack *s);
void		op_push(t_stack *from, t_stack *to);

/* named ops (with write) */
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/* validation */
void		error_exit(t_stack *a, t_stack *b);
int			is_number(char *str);
int			is_duplicate(t_stack *s, int value);

/* indexing */
void		assign_index(t_stack *a);
void		reset_indexes(t_stack *a);
t_stack		*find_min(t_stack *a);
t_stack		*find_max(t_stack *b);
void		sort_simple(t_stack *a, t_stack *b);
int			is_sorted(t_stack *a);
void		push_chunks(t_stack *a, t_stack *b);
void		chunk_sort(t_stack *a, t_stack *b);
int			steps_to_top(t_stack *a, t_stack *node);
void		sort_radix(t_stack *a, t_stack *b);

/* bench */
void		init_count(t_count *cnt);
void		count_op(t_stack *s, int op);
int			total_ops(t_count *cnt);
char		*strat_name(t_strategy s);
char		*strat_class(t_strategy s);
void		print_bench(t_args *opts, t_count *cnt);

#endif
