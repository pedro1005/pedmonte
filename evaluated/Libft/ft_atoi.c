/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:43:14 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/24 12:48:12 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+')
	{
		i++;
	}
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * res);
}
/*
int main()
{
	char *s;

	s = "\n\n\n  -46\b9 \n5d6";
	printf("%d\n", ft_atoi(s));
	printf("%d", atoi(s));
	return (0);
}*/
