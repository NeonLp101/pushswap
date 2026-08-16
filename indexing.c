/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 18:19:04 by jihchoi           #+#    #+#             */
/*   Updated: 2026/06/08 18:45:52 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min_unindexed(t_stack *a)
{
	t_stack	*cur;
	t_stack	*min;

	cur = a->next;
	min = NULL;
	while (cur != a)
	{
		if (cur->index == -1)
		{
			if (!min || cur->value < min->value)
				min = cur;
		}
		cur = cur->next;
	}
	return (min);
}

void	reset_indexes(t_stack *a)
{
	t_stack	*cur;

	cur = a->next;
	while (cur != a)
	{
		cur->index = -1;
		cur = cur->next;
	}
}

void	assign_index(t_stack *a)
{
	t_stack	*node;
	int		index;

	reset_indexes(a);
	index = 0;
	while (index < a->value)
	{
		node = find_min_unindexed(a);
		if (!node)
			return ;
		node->index = index;
		index++;
	}
}

double	compute_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	long	mistakes;
	long	total;

	if (a->value < 2)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = a->next;
	while (i != a)
	{
		j = i->next;
		while (j != a)
		{
			total++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total);
}
