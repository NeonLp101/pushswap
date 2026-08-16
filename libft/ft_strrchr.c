/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:48:01 by jihchoi           #+#    #+#             */
/*   Updated: 2026/05/04 15:56:04 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			last = ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		last = ((char *)&s[i]);
	return (last);
}
