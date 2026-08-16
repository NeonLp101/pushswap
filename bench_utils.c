/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:00:00 by lernst            #+#    #+#             */
/*   Updated: 2026/06/13 12:00:00 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_count(t_count *cnt)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		cnt->ops[i] = 0;
		i++;
	}
}

void	count_op(t_stack *s, int op)
{
	if (s->cnt)
		s->cnt->ops[op]++;
}

int	total_ops(t_count *cnt)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
	{
		total += cnt->ops[i];
		i++;
	}
	return (total);
}

char	*strat_name(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("Simple");
	if (s == STRAT_MEDIUM)
		return ("Medium");
	if (s == STRAT_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*strat_class(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("O(n^2)");
	if (s == STRAT_MEDIUM)
		return ("O(n√n)");
	return ("O(n log n)");
}
