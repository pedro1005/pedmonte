/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:22:18 by pedmonte          #+#    #+#             */
/*   Updated: 2023/05/31 16:37:41 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
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
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	temp = malloc((ft_strlen(static_data) + ft_strlen(buff) + 1)
			* sizeof(char));
	if (!static_data || !buff || temp == NULL)
	{
		free (static_data);
		return (NULL);
	}
	while ((static_data)[++i] != '\0')
		temp[i] = (static_data)[i];
	while (buff[j] != '\0')
		temp[i++] = buff[j++];
	temp[i] = '\0';
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
