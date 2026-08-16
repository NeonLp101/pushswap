/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:15:19 by jihchoi           #+#    #+#             */
/*   Updated: 2026/06/08 18:45:31 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_stack *s)
{
	t_stack	*first;

	if (s->value < 2)
		return ;
	first = s->next;
	s->next = first->next;
	first->next->prev = s;
	first->prev = s->prev;
	first->next = s;
	s->prev->next = first;
	s->prev = first;
}

void	op_reverse_rotate(t_stack *s)
{
	t_stack	*last;

	if (s->value < 2)
		return ;
	last = s->prev;
	s->prev = last->prev;
	last->prev->next = s;
	last->next = s->next;
	last->prev = s;
	s->next->prev = last;
	s->next = last;
}

void	ra(t_stack *a)
{
	op_rotate(a);
	count_op(a, OP_RA);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	op_rotate(b);
	count_op(b, OP_RB);
	write(1, "rb\n", 3);
}
