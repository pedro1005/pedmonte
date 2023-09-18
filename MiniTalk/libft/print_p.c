/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:50:54 by pedmonte          #+#    #+#             */
/*   Updated: 2023/06/22 14:21:39 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_address(unsigned long long address, int num_chars)
{
	int		digit;
	int		i;
	char	*address_str;

	i = 0;
	address_str = malloc((num_chars + 3) * sizeof(char));
	address_str[0] = '0';
	address_str[1] = 'x';
	i = num_chars + 1;
	while (address != 0)
	{
		digit = address % 16;
		if (digit < 10)
			address_str[i] = '0' + digit;
		else
			address_str[i] = 'a' + (digit - 10);
		address /= 16;
		i--;
	}
	write(1, address_str, num_chars + 2);
	free(address_str);
}

int	print_p(char *temp, va_list ptr)
{
	unsigned long long	address;
	unsigned long long	temp_address;
	int					num_chars;

	temp = va_arg(ptr, char *);
	num_chars = 0;
	if (temp == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long long)temp;
	temp_address = address;
	while (temp_address != 0)
	{
		temp_address /= 16;
		num_chars++;
	}
	print_address(address, num_chars);
	return (num_chars + 2);
}
