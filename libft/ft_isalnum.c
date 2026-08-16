/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:51:49 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/23 19:02:23 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int main(void)
{
	char chr1 = 'A';
	char chr2 = 'z';
	char chr3 = '1';
	char chr4 = ' ';
	char chr5 = ')';

	printf("A = %d\n", ft_isalnum(chr1));
	printf("z = %d\n", ft_isalnum(chr2));
	printf("1 = %d\n", ft_isalnum(chr3));
	printf("  = %d\n", ft_isalnum(chr4));
	printf(") = %d\n", ft_isalnum(chr5));
}*/
