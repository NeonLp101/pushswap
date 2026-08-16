/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:50:16 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/23 20:38:55 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = 0;
	dstlen = 0;
	while (src[srclen])
		srclen++;
	while (dst[dstlen])
		dstlen++;
	if (dstlen >= size)
		return (size + srclen);
	while (src[i] && (dstlen + i) < (size - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (srclen + dstlen);
}
/*
int	main(void)
{
	char	dst1[20] = "Hello sival";
	char	dst2[20] = "Hello";
	char	dst3[20] = "Hello";
	char	src[] = "42";
	size_t	ret;

	// Test 1: normal case
	ret = ft_strlcat(dst1, src, sizeof(dst1));
	printf("dst1: %s\n", dst1);
	printf("return: %zu\n\n", ret);

	// Test 2: small buffer (truncation)
	ret = ft_strlcat(dst2, src, 6);
	printf("dst2: %s\n", dst2);
	printf("return: %zu\n\n", ret);

	// Test 3: no space at all
	ret = ft_strlcat(dst3, src, 1);
	printf("dst3: %s\n", dst3);
	printf("return: %zu\n\n", ret);

	return (0);
}*/
