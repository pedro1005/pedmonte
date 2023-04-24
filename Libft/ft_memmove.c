/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:59:01 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/18 15:00:16 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s = (const char *)src;

	d = (char *)dest;
	if (dest <= src)
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		s = s + n;
		d = d + n;
		while (n)
		{
			*--d = *--s;
			n--;
		}
	}
	return (dest);
}
/*
int main()
{
char csrc[100] = "Geeksfor";
ft_memmove(csrc+5, csrc, strlen(csrc)+1);
printf("%s", csrc);
return 0;
}
*/
