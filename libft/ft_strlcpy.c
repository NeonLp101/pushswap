/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:54:47 by jihchoi           #+#    #+#             */
/*   Updated: 2026/05/04 15:04:17 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
/*
#include <stdio.h>

int main(void)
{
	char	src[] = "Hello 42 Seoul";
	char	dst[20];
	char	dst2[20];
	size_t	ret;

	// test 1: normal case
	ret = ft_strlcpy(dst, src, sizeof(dst));
	printf("dst: %s\n", dst);
	printf("return (src len): %zu\n\n", ret);

	// test 2: small buffer (truncation case)
	ret = ft_strlcpy(dst2, src, 5);
	printf("dst2: %s\n", dst2);
	printf("return (src len): %zu\n\n", ret);

	return (0);
}
*/
