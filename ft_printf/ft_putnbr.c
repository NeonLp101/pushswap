/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:51:24 by lernst            #+#    #+#             */
/*   Updated: 2026/05/08 22:25:27 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	n_negative(long n)
{
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

int	ft_putnbr(int n)
{
	char	c;
	int		len;

	if (n_negative((long)n))
		return (11);
	if (n < 0)
	{
		write(1, "-", 1);
		return (1 + ft_putnbr(-n));
	}
	len = 0;
	if (n > 9)
		len = ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (len + 1);
}
