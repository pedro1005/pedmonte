/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:11:09 by pedmonte          #+#    #+#             */
/*   Updated: 2023/06/22 12:12:47 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char *temp, va_list ptr)
{
	int	j;

	j = 0;
	temp = va_arg(ptr, char *);
	if (temp == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (temp[j])
	{
		write(1, &temp[j], 1);
		j++;
	}
	j++;
	return (j - 1);
}
