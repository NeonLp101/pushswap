/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:35:39 by jihchoi           #+#    #+#             */
/*   Updated: 2026/05/05 14:45:12 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dup_word(char const *s, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **res, int i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	process_split(char **res, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			res[i] = dup_word(s, len);
			if (!res[i])
			{
				free_all(res, i);
				return (-1);
			}
			i++;
			s += len;
		}
	}
	res[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (0);
	if (process_split(res, s, c) == -1)
		return (0);
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>

static void print_split(char **res)
{
    int i = 0;

    if (!res)
    {
        printf("NULL\n");
        return;
    }

    while (res[i])
    {
        printf("[%s]\n", res[i]);
        i++;
    }
    printf("[NULL]\n");
}

static void free_split(char **res)
{
    int i = 0;

    if (!res)
        return;

    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}

int main(void)
{
    char **res;

    printf("---- TEST 1 ----\n");
    res = ft_split("hello 42 school", ' ');
    print_split(res);
    free_split(res);

    printf("\n---- TEST 2 ----\n");
    res = ft_split("   hello   42   school   ", ' ');
    print_split(res);
    free_split(res);

    printf("\n---- TEST 3 ----\n");
    res = ft_split("aaaaa", 'a');
    print_split(res);
    free_split(res);

    printf("\n---- TEST 4 ----\n");
    res = ft_split("", ' ');
    print_split(res);
    free_split(res);

    printf("\n---- TEST 5 ----\n");
    res = ft_split("one:two::three", ':');
    print_split(res);
    free_split(res);

    printf("\n---- TEST 6 ----\n");
    res = ft_split(NULL, ' ');
    print_split(res);
    free_split(res);

    return (0);
}*/
