/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:33:23 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/14 11:50:10 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset() is used to fill a block of memory with a particular value.

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t    i;

	i = 0;
	unsigned char	*ptr;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i++] = (unsigned char)c;
	}
	return s;
}

int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore ft_memset(): %s\n", str);

    // Fill 8 characters starting from str[13] with '.'
    ft_memset(str + 13, '.', 8*sizeof(char));

    printf("After ft_memset():  %s", str);
    return 0;
}
