/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:49:15 by jihchoi           #+#    #+#             */
/*   Updated: 2026/06/08 18:45:10 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_stack *s)
{
	t_stack	*first;
	t_stack	*second;

	if (s->value < 2)
		return ;
	first = s->next;
	second = first->next;
	s->next = second;
	second->prev = s;
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->next = first;
}

void	op_push(t_stack *from, t_stack *to)
{
	t_stack	*node;

	if (from->next == from)
		return ;
	node = from->next;
	from->next = node->next;
	node->next->prev = from;
	from->value--;
	add_front(to, node);
}

void	sa(t_stack *a)
{
	op_swap(a);
	count_op(a, OP_SA);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	op_swap(b);
	count_op(b, OP_SB);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	op_swap(a);
	op_swap(b);
	count_op(a, OP_SS);
	write(1, "ss\n", 3);
}
