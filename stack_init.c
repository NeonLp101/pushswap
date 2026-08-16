/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:15:32 by jihchoi           #+#    #+#             */
/*   Updated: 2026/05/22 17:45:39 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->value = 0;
	s->index = 0;
	s->next = s;
	s->prev = s;
	s->cnt = NULL;
	return (s);
}

t_stack	*node_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	node->cnt = NULL;
	return (node);
}

void	add_back(t_stack *s, t_stack *node)
{
	node->next = s;
	node->prev = s->prev;
	s->prev->next = node;
	s->prev = node;
	s->value++;
}

void	add_front(t_stack *s, t_stack *node)
{
	node->prev = s;
	node->next = s->next;
	s->next->prev = node;
	s->next = node;
	s->value++;
}

void	stack_clear(t_stack *s)

{
	t_stack	*cur;
	t_stack	*nxt;

	if (!s)
		return ;
	cur = s->next;
	while (cur != s)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	free(s);
}
