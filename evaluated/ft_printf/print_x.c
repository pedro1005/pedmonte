/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:20:40 by pedmonte          #+#    #+#             */
/*   Updated: 2023/06/22 12:34:21 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_x_len(unsigned int temp_value)
{
	int	len;

	len = 1;
	while (temp_value >= 16)
	{
		len++;
		temp_value = temp_value / 16;
	}
	return (len);
}

int	print_x(char *temp, va_list ptr)
{
	unsigned int	value;
	int				length;
	unsigned int	temp_value;
	int				index;

	value = va_arg(ptr, unsigned int);
	temp_value = value;
	length = get_x_len(temp_value);
	temp = (char *)malloc((length + 1) * sizeof(char));
	index = length - 1;
	while (index >= 0)
	{
		temp[index] = '0' + (value % 16);
		if (temp[index] < 48 || temp[index] > 57)
			temp[index] = temp[index] + 39;
		value /= 16;
		index--;
	}
	temp[length] = '\0';
	write(1, temp, length);
	free(temp);
	return (length);
}
