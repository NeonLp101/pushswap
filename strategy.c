/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:00:00 by lernst            #+#    #+#             */
/*   Updated: 2026/06/08 18:39:07 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	match_flag(char *arg, char *flag)
{
	int	i;

	i = 0;
	while (arg[i] && flag[i] && arg[i] == flag[i])
		i++;
	return (arg[i] == 0 && flag[i] == 0);
}

static int	apply_flag(char *arg, t_args *opts)
{
	if (match_flag(arg, "--simple"))
		opts->requested = STRAT_SIMPLE;
	else if (match_flag(arg, "--medium"))
		opts->requested = STRAT_MEDIUM;
	else if (match_flag(arg, "--complex"))
		opts->requested = STRAT_COMPLEX;
	else if (match_flag(arg, "--adaptive"))
		opts->requested = STRAT_ADAPTIVE;
	else if (match_flag(arg, "--bench"))
		opts->bench = 1;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_args *opts)
{
	int	i;

	opts->requested = STRAT_ADAPTIVE;
	opts->resolved = STRAT_ADAPTIVE;
	opts->disorder = 0.0;
	opts->bench = 0;
	i = 1;
	while (i < argc && apply_flag(argv[i], opts))
		i++;
	return (i);
}

t_strategy	pick_adaptive(double disorder)
{
	if (disorder < 0.2)
		return (STRAT_SIMPLE);
	if (disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	run_strategy(t_stack *a, t_stack *b, t_strategy s)
{
	if (s == STRAT_SIMPLE)
		sort_simple(a, b);
	else if (s == STRAT_MEDIUM)
		chunk_sort(a, b);
	else
		sort_radix(a, b);
}
