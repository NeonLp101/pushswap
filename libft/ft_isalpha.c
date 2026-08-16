/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:05:15 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/23 19:04:31 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	char chr1 = 'A';
	char chr2 = 'S';
	char chr3 = 'z';
	char chr4 = ' ';
	char chr5 = '>';

	printf("A = %d\n", ft_isalpha(chr1));
	printf("S = %d\n", ft_isalpha(chr2));
	printf("z = %d\n", ft_isalpha(chr3));
	printf("  = %d\n", ft_isalpha(chr4));
	printf("> = %d\n", ft_isalpha(chr5));
}*/
