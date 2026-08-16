/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <jihchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:19:04 by jihchoi           #+#    #+#             */
/*   Updated: 2026/05/22 15:42:24 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
	stack_clear(a);
	stack_clear(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *s, int value)
{
	t_stack	*cur;

	cur = s->next;
	while (cur != s)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}
