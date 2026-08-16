/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:14:53 by jihchoi           #+#    #+#             */
/*   Updated: 2026/04/24 01:26:31 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int *arr = ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    void *ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
    if (!ptr)
        printf("Overflow handled\n");

    free(arr);
    return (0);
}*/
