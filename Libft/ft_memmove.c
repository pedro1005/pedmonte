/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:59:01 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/30 11:18:02 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (!n)
		return (dest);
	if (dest <= src)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		s = s + n;
		d = d + n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
