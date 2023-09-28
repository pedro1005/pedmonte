/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:47:44 by pedmonte          #+#    #+#             */
/*   Updated: 2023/06/22 11:50:19 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_d(char *temp, va_list ptr)
{
	int	j;

	j = 0;
	temp = ft_itoa(va_arg(ptr, int));
	while (temp[j])
	{
		write(1, &temp[j], 1);
		j++;
	}
	j++;
	free(temp);
	return (j - 1);
}
