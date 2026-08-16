/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:46:57 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/23 19:06:56 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main(void)
{
	char	data[] = "Hello 42 Seoul";
	void	*res;

	// Test 1: normal case (inside string)
	res = ft_memchr(data, '4', strlen(data));
	printf("Test 1: %s\n", (char *)res);

	// Test 2: first character
	res = ft_memchr(data, 'H', strlen(data));
	printf("Test 2: %s\n", (char *)res);

	// Test 3: last character
	res = ft_memchr(data, 'l', strlen(data));
	printf("Test 3: %s\n", (char *)res);

	// Test 4: not found
	res = ft_memchr(data, 'z', strlen(data));
	printf("Test 4: %p\n", res);

	// Test 5: search inside raw memory (including '\0')
	res = ft_memchr(data, '\0', strlen(data) + 1);
	printf("Test 5: %p\n", res);

	return (0);
}
*/
