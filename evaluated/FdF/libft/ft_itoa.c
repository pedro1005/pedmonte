/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:28:16 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/25 12:18:16 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	count_chars(long number)
{
	long	count;

	count = 0;
	if (number == 0)
		return ((long)1);
	if (number < 0)
	{
		number = -number;
		count++;
	}
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int number)
{
	char	*res;
	int		len;
	int		sign;
	long	n;

	n = number;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	len = count_chars(n);
	res = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!res)
		return (NULL);
	res[len + sign] = '\0';
	while (len-- > 0)
	{
		res[len + sign] = '0' + (n % 10);
		n /= 10;
	}
	if (sign)
		res[0] = '-';
	return (res);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(0));
	return (0);
}*/
