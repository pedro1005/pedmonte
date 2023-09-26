/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:27:02 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/19 17:02:51 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	size;
	int		i;

	if (!s)
		return (NULL);
	size = 0;
	i = 0;
	while (s[size])
		size++;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < (int)size)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
int main()
{
    char source[] = "GeeksForGeeks";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = ft_strdup(source);

    printf("%s", target);
    return 0;
}*/
