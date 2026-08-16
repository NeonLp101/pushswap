/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:43:29 by lernst            #+#    #+#             */
/*   Updated: 2026/06/08 18:44:43 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	op_rotate(a);
	op_rotate(b);
	count_op(a, OP_RR);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	op_reverse_rotate(a);
	count_op(a, OP_RRA);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	op_reverse_rotate(b);
	count_op(b, OP_RRB);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	op_reverse_rotate(a);
	op_reverse_rotate(b);
	count_op(a, OP_RRR);
	write(1, "rrr\n", 4);
}
