/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:29:04 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/25 12:53:45 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (res == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
int main()
{
	char my_func(unsigned int i, char str)
	{
 	printf("My inner function: index = %d and %c\n", i, str);
 	return str - 32;
	}
	char	*s;
	s = "aaaAAaaabbBBBbb";
	printf("%s", ft_strmapi(s, my_func));
	return(0);
}*/
