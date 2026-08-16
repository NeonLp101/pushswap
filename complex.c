/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:30:00 by lernst            #+#    #+#             */
/*   Updated: 2026/06/08 18:38:58 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n - 1) >> bits)
		bits++;
	return (bits);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	bits;
	int	i;
	int	j;

	if (a->value <= 1 || is_sorted(a))
		return ;
	assign_index(a);
	bits = count_bits(a->value);
	i = -1;
	while (++i < bits)
	{
		j = a->value;
		while (j-- > 0)
		{
			if ((a->next->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->value > 0)
			pa(a, b);
	}
}
