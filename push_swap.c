/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:00:14 by jihchoi           #+#    #+#             */
/*   Updated: 2026/06/13 12:00:00 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	parse_long(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > INT_MAX)
			return ((long)INT_MAX + 1);
		if (sign == -1 && - num < INT_MIN)
			return ((long)INT_MIN - 1);
		i++;
	}
	return (num * sign);
}

static void	push_arg(t_stack *a, t_stack *b, char *arg)
{
	long	num;
	t_stack	*node;

	if (!is_number(arg))
		error_exit(a, b);
	num = parse_long(arg);
	if (num > INT_MAX || num < INT_MIN)
		error_exit(a, b);
	if (is_duplicate(a, (int)num))
		error_exit(a, b);
	node = node_new((int)num);
	if (!node)
		error_exit(a, b);
	add_back(a, node);
}

static void	load_args(t_stack *a, t_stack *b, char **args)
{
	while (*args)
	{
		push_arg(a, b, *args);
		args++;
	}
}

static void	run_sort(t_stack *a, t_stack *b, t_args *opts)
{
	opts->disorder = compute_disorder(a);
	opts->resolved = opts->requested;
	if (opts->resolved == STRAT_ADAPTIVE)
		opts->resolved = pick_adaptive(opts->disorder);
	if (a->value > 1 && !is_sorted(a))
	{
		assign_index(a);
		run_strategy(a, b, opts->resolved);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_args	opts;
	t_count	cnt;
	int		i;

	i = parse_flags(argc, argv, &opts);
	if (i >= argc)
		return (0);
	a = stack_new();
	b = stack_new();
	if (!a || !b)
		error_exit(a, b);
	init_count(&cnt);
	a->cnt = &cnt;
	b->cnt = &cnt;
	load_args(a, b, argv + i);
	run_sort(a, b, &opts);
	if (opts.bench)
		print_bench(&opts, &cnt);
	stack_clear(a);
	stack_clear(b);
	return (0);
}
