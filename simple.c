/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:00:00 by lernst            #+#    #+#             */
/*   Updated: 2026/06/08 18:39:44 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *a)
{
	t_stack	*cur;
	t_stack	*min_node;

	cur = a->next;
	min_node = cur;
	while (cur != a)
	{
		if (cur->value < min_node->value)
			min_node = cur;
		cur = cur->next;
	}
	return (min_node);
}

int	steps_to_top(t_stack *a, t_stack *node)
{
	t_stack	*cur;
	int		pos;
	int		size;

	cur = a->next;
	pos = 0;
	size = a->value;
	while (cur != node)
	{
		pos++;
		cur = cur->next;
	}
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

static void	rotate_to_top(t_stack *a, t_stack *node)
{
	int	steps;

	steps = steps_to_top(a, node);
	while (steps > 0)
	{
		ra(a);
		steps--;
	}
	while (steps < 0)
	{
		rra(a);
		steps++;
	}
}

int	is_sorted(t_stack *a)
{
	t_stack	*cur;

	cur = a->next;
	while (cur->next != a)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	sort_simple(t_stack *a, t_stack *b)
{
	t_stack	*min_node;
	int		size;
	int		i;

	if (a->value <= 1 || is_sorted(a))
		return ;
	size = a->value;
	i = 0;
	while (i < size - 1)
	{
		min_node = find_min(a);
		rotate_to_top(a, min_node);
		pb(a, b);
		i++;
	}
	while (b->value > 0)
		pa(a, b);
}
