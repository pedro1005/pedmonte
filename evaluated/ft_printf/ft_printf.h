/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:17:21 by pedmonte          #+#    #+#             */
/*   Updated: 2023/06/13 10:17:27 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		print_s(char *temp, va_list ptr);
int		print_d(char *temp, va_list ptr);
int		print_c(char *temp, va_list ptr);
int		print_u(char *temp, va_list ptr);
int		print_x(char *temp, va_list ptr);
int		print_upx(char *temp, va_list ptr);
int		print_p(char *temp, va_list ptr);
long	count_chars(long number);
char	*ft_itoa(int number);
int		get_x_len(unsigned int temp_value);
void	print_address(unsigned long long address, int num_chars);
int		print_formats(const char *str, int i, int n_chars, va_list ptr);

#endif
