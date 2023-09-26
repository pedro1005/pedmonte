/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:39:13 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/02 14:40:08 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	isvalid(char c)
{
	const char	*digits;
	const char	*digits2;

	digits = "0123456789abcdef";
	digits2 = "0123456789ABCDEF";
	while (*digits || *digits2)
	{
		if (*digits == c || *digits2 == c)
			return (1);
		digits++;
		digits2++;
	}
	return (0);
}

int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	while (isvalid(*str))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}
