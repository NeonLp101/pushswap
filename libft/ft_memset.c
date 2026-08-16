/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:44:12 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/23 20:42:58 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *dst, int c, size_t len);

int	main(void)
{
	char	str1[10];
	char	str2[10];
	int		i;

	// initialize with same values
	for (i = 0; i < 10; i++)
	{
		str1[i] = 'X';
		str2[i] = 'X';
	}

	// apply memset
	ft_memset(str1, 'A', 5);
	memset(str2, 'A', 5);

	// print results
	printf("ft_memset: ");
	for (i = 0; i < 10; i++)
		printf("%c ", str1[i]);

	printf("\nmemset:    ");
	for (i = 0; i < 10; i++)
		printf("%c ", str2[i]);

	printf("\n");

	return (0);
}*/
