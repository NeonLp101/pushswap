/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:02:21 by jihchoi           #+#    #+#             */
/*   Updated: 2026/05/01 18:52:16 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		len;

	num = n;
	len = count_len(num);
	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	if (num == 0)
		res[0] = '0';
	while (num > 0)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
