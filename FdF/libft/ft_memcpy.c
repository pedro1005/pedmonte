/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:15:31 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/24 12:15:37 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*original_dst;

	if (!dst && !src)
		return (NULL);
	original_dst = dst;
	while (n--)
		*((char *)dst++) = *((char *)src++);
	return (original_dst);
}
/*

int main(void)
{
	char src[50] = "mahmudulhasanjony";
	char dest[50];
	char *ret;

	ret = ft_memcpy(dest, src, 9);
	printf("%s", ret);
	return (0);
}*/
