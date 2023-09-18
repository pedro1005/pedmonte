/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:37:58 by pedmonte          #+#    #+#             */
/*   Updated: 2023/06/22 12:42:10 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_upx(char *temp, va_list ptr)
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
			temp[index] = temp[index] + 7;
		value /= 16;
		index--;
	}
	temp[length] = '\0';
	write(1, temp, length);
	free(temp);
	return (length);
}
