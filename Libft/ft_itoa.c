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

static int	count_chars(long number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		number = number * -1;
		count++;
	}
	while (number > 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int number)
{
	char	*res;
	int		n;

	n = count_chars(number);
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	res[n] = '\0';
	if (number == 0)
		return ("0");
	if (number == -2147483648)
		return ("-2147483648");
	if (number < 0)
	{
		res[0] = '-';
		number = number * -1;
	}
	while (number > 0)
	{
		res[--n] = 48 + (number % 10);
		number = number / 10;
	}
	return (res);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(0));
	return (0);
}*/
