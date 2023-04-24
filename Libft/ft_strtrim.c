/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:34:35 by pedmonte          #+#    #+#             */
/*   Updated: 2023/04/24 17:27:04 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int	s;
	int	st;
	int	r;

	i = 0;
	j = 0;
	k = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1[s] && s1[s] != set[st])
	{
		res[r] = s1[s];
		s++;
		r++;
		while (set[st] == s1[s])
		{
			st++;
			s++;
			if (set[st] == 0)
				break;
		}



}
