/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:22:18 by pedmonte          #+#    #+#             */
/*   Updated: 2023/05/31 16:37:41 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_cpy(char *src, char *src2, char *dst)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (src2[j] != '\0')
	{
		dst[i] = src2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*str_join(char *static_data, char *buff)
{
	char	*temp;

	if (!static_data)
	{
		static_data = malloc(1 * sizeof(char));
		static_data[0] = '\0';
	}
	if (!static_data || !buff)
	{
		free (static_data);
		return (NULL);
	}
	temp = malloc((ft_strlen(static_data) + ft_strlen(buff) + 1)
			* sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp = str_cpy(static_data, buff, temp);
	free(static_data);
	static_data = temp;
	return (static_data);
}

int	find_char(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s || !c)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*check_static_data(char *static_data)
{
	if (!static_data)
	{
		static_data = malloc(BUFFER_SIZE + 1);
		if (!static_data)
			return (NULL);
		static_data[0] = '\0';
	}
	return (static_data);
}
