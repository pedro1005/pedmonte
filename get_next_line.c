/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:31:21 by pedmonte          #+#    #+#             */
/*   Updated: 2023/05/11 17:08:34 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*data;
	char		*res_line;
	static ssize_t	res_read;
	int		i;
	static int	j;
	
	if (fd < 0)
		return (NULL);
	i = 0;
	if (j == 0)
		j = 0;
	if (data == 0)
		data = malloc(BUFFER_SIZE);
	if (res_read == 0)
		res_read = read(fd, data, BUFFER_SIZE);
	res_line = malloc(BUFFER_SIZE + 1);
	if (!res_line)
		return ('\n');
	while (*(data + j) != '\n' && (j < BUFFER_SIZE))
	{
		res_line[i] = *(data + j);
		i++;
		j++;
	}
	j++;
	if (j < res_read)
	{
		res_line[i] = '\n';
		res_line[++i] = '\0';
	}
	else
		res_line[i] = '\0';
	if (j>= res_read)
	{
		free(data);
		data = NULL;
	}
	return (res_line);
}

int main()
{
	FILE	*fp = fopen("test.txt", "r");
	int	fd = fileno(fp);
	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	
	return (0);
}
