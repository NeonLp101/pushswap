/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:04:36 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/23 19:10:30 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *s, int c);

int main(void)
{
	const char *str = "Hello 42 Seoul";

	// Test 1: normal character in middle
	printf("Test 1: %s\n", ft_strchr(str, '4'));

	// Test 2: first character
	printf("Test 2: %s\n", ft_strchr(str, 'H'));

	// Test 3: last character before null
	printf("Test 3: %s\n", ft_strchr(str, 'l'));

	// Test 4: character not found
	printf("Test 4: %p\n", (void *)ft_strchr(str, 'z'));

	// Test 5: search for '\0' (IMPORTANT)
	printf("Test 5: %p\n", (void *)ft_strchr(str, '\0'));

	// Test 6: empty string
	printf("Test 6: %p\n", (void *)ft_strchr("", 'a'));

	// Test 7: compare with libc
	printf("Libc   : %s\n", strchr(str, '4'));

	return (0);
}*/
