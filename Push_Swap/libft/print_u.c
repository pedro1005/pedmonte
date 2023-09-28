/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:13:05 by pedmonte          #+#    #+#             */
/*   Updated: 2023/06/22 12:20:15 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_u(char *temp, va_list ptr)
{
	unsigned int	value;
	int				length;
	unsigned int	temp_value;
	int				index;

	value = va_arg(ptr, unsigned int);
	length = 1;
	temp_value = value;
	while (temp_value >= 10)
	{
		length++;
		temp_value = temp_value / 10;
	}
	temp = (char *)malloc((length + 1) * sizeof(char));
	index = length - 1;
	while (index >= 0)
	{
		temp[index] = '0' + (value % 10);
		value /= 10;
		index--;
	}
	temp[length] = '\0';
	write(1, temp, length);
	free(temp);
	return (length);
}
