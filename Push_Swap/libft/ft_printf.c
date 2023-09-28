/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:16:19 by pedmonte          #+#    #+#             */
/*   Updated: 2023/06/22 14:43:32 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_formats(const char *str, int i, int n_chars, va_list ptr)
{
	char	*temp;

	temp = NULL;
	if (str[i] == 's')
		n_chars += print_s(temp, ptr);
	if (str[i] == 'd' || str[i] == 'i')
		n_chars += print_d(temp, ptr);
	if (str[i] == 'c')
		n_chars += print_c(temp, ptr);
	if (str[i] == 'p')
		n_chars += print_p(temp, ptr);
	if (str[i] == 'u')
		n_chars += print_u(temp, ptr);
	if (str[i] == 'x')
		n_chars += print_x(temp, ptr);
	if (str[i] == 'X')
		n_chars += print_upx(temp, ptr);
	if (str[i] == '%')
	{
		write(1, "%", 1);
		n_chars += 1;
	}
	return (n_chars);
}

int	ft_printf(const char *str, ...)
{
	int		n_chars;
	va_list	ptr;
	int		i;

	i = 0;
	n_chars = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			n_chars = print_formats(str, i, n_chars, ptr);
		}
		else
		{
			write(1, &str[i], 1);
			n_chars++;
		}
		i++;
	}
	va_end(ptr);
	return (n_chars);
}
