/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:06:38 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/27 17:19:58 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const *set)
{
	size_t	len_s1;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	len_s1 = ft_strlen(s1);
	end = len_s1 - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
