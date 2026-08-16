/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihchoi <jihchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:52:16 by jihchoi           #+#    #+#             */
/*   Updated: 2026/05/22 15:41:51 by jihchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	sign;
	long	ret;

	sign = 1;
	ret = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * ret);
}
/*
int main(void)
{
	printf("%d\n", ft_atoi("123"));
	printf("%d\n", ft_atoi("-123"));
	printf("%d\n", ft_atoi("  123"));
	printf("%d\n", ft_atoi("++-123"));
	printf("%d\n", ft_atoi("abc123"));
	printf("123 = %d\n", ft_atoi("123"));
	printf("   -42 = %d\n", ft_atoi("   -42"));
	printf("++123 = %d\n", ft_atoi("++123"));
	printf("abc123 = %d\n", ft_atoi("abc123"));
	printf("123abc = %d\n", ft_atoi("123abc"));
	printf("42 = %d\n", ft_atoi("\t\n 42"));
	printf("   +-42 = %d\n", ft_atoi("   +-42"));
	printf(" = %d\n", ft_atoi(""));
	printf("   = %d\n", ft_atoi("     "));
	printf("-00042 = %d\n", ft_atoi("-00042"));
}
*/
