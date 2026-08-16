/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:35:38 by jihchoi           #+#    #+#             */
/*   Updated: 2026/06/08 18:37:25 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *b)
{
	t_stack	*cur;
	t_stack	*max;

	cur = b->next;
	max = cur;
	while (cur != b)
	{
		if (cur->index > max->index)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

static void	push_back(t_stack *a, t_stack *b)
{
	t_stack	*max;
	int		steps;

	while (b->value > 0)
	{
		max = find_max(b);
		steps = steps_to_top(b, max);
		while (steps > 0)
		{
			rb(b);
			steps--;
		}
		while (steps < 0)
		{
			rrb(b);
			steps++;
		}
		pa(a, b);
	}
}

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk * 2);
}

void	push_chunks(t_stack *a, t_stack *b)
{
	int	current;
	int	chunk;

	current = 0;
	chunk = get_chunk_size(a->value);
	while (a->value > 0)
	{
		if (a->next->index <= current)
		{
			pb(a, b);
			rb(b);
			current++;
		}
		else if (a->next->index <= current + chunk)
		{
			pb(a, b);
			current++;
		}
		else
			ra(a);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	push_chunks(a, b);
	push_back(a, b);
}
