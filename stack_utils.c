/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:39:04 by jihchoi           #+#    #+#             */
/*   Updated: 2026/06/14 17:15:22 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	t_stack	*cur;

	cur = s->next;
	while (cur != s)
	{
		ft_printf("%d (%d)\n", cur->value, cur->index);
		cur = cur->next;
	}
}
