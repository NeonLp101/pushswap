/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:44:23 by lernst            #+#    #+#             */
/*   Updated: 2026/06/08 18:44:33 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->next == b)
		return ;
	op_push(b, a);
	count_op(a, OP_PA);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->next == a)
		return ;
	op_push(a, b);
	count_op(a, OP_PB);
	write(1, "pb\n", 3);
}
