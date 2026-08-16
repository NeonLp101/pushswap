/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 02:42:20 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/24 03:13:41 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char	*s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (0);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int main (void)
{
	char *s = "Hello";
	char *d = ft_strdup(s);

	printf("s1 = %s\n", s);
	printf("s adress = %p\n",(void *)s);

	printf("d = %s\n", d);
	printf("d adress = %p\n", (void *)d);

	if (s != d)
		printf("ok");
	else
		printf("go die");
	free(d);
	return (0);
}*/
