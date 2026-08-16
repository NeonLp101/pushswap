/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:18:26 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/23 19:05:47 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	char chr1 = '0';
	char chr2 = '9';
	char chr3 = ' ';
	char chr4 = 'a';
	char chr5 = '>';

	printf("0 =%d\n", ft_isdigit(chr1));
	printf("9 =%d\n", ft_isdigit(chr2));
	printf("  =%d\n", ft_isdigit(chr3));
	printf("a =%d\n", ft_isdigit(chr4));
	printf("> =%d\n", ft_isdigit(chr5));
}*/
