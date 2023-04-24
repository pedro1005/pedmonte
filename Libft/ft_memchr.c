/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:40:45 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/24 12:17:40 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (((char *)s)[i] && n > 0)
	{
		if (((char *)s)[i] == (char)c)
			return ((unsigned char *)s + i);
		i++;
		n--;
	}
	return (0);
}
/*
int main()
{
	char *s;
	s = "Escola42";
	printf("%s", (char *)ft_memchr(s, 'a', 5));
	return (0);
}
*/
