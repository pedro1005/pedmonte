/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:39:02 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/24 16:33:23 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	if (!s1)
		s1 = "";
	while (s1[i] && i < len)
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] && i < len)
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}
/*
int main()
{
	printf("%s", ft_strjoin("Ola ", "Mundo!"));
	return (0);
}*/
