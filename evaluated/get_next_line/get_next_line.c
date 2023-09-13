/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:19:15 by pedmonte          #+#    #+#             */
/*   Updated: 2023/05/31 16:21:04 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*Read data from fd and updates static_data when finds \n or EOF*/
char	*update_data(int fd, char *static_data)
{
	ssize_t	read_fd;
	char	*buff;

	read_fd = 1;
	static_data = check_static_data(static_data);
	while (!find_char(static_data, '\n') && read_fd != 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return (NULL);
		read_fd = read(fd, buff, BUFFER_SIZE);
		if (read_fd == -1)
		{
			free(static_data);
			free(buff);
			return (NULL);
		}
		buff[read_fd] = '\0';
		static_data = str_join(static_data, buff);
		free(buff);
		if (!static_data)
			return (NULL);
	}
	return (static_data);
}

char	*update_line(char *static_data)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!static_data)
		return (NULL);
	while (static_data[i] && static_data[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	line = line_cpy(static_data, line);
	if (!line[0])
	{
		free(line);
		free(static_data);
		return (NULL);
	}
	return (line);
}

char	*line_cpy(char *static_data, char *line)
{
	size_t	i;

	i = 0;
	while (static_data[i])
	{
		line[i] = static_data[i];
		if (static_data[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*cut_static_data(char **static_data, size_t str_len)
{
	char		*temp;
	size_t		i;
	int			j;

	if (!(*static_data) || !str_len)
		return (NULL);
	i = str_len - 1;
	j = 0;
	while (((*static_data))[i])
	{
		i++;
		j++;
	}
	temp = malloc((j + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = i - j + 1;
	j = 0;
	while ((*static_data)[i])
		temp[j++] = (*static_data)[i++];
	temp[j] = '\0';
	free(*static_data);
	*static_data = temp;
	return (*static_data);
}

char	*get_next_line(int fd)
{
	static char	*static_data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_data = update_data(fd, static_data);
	line = update_line(static_data);
	static_data = cut_static_data(&static_data, ft_strlen(line));
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("tests/test.txt", O_RDONLY);
    	if (fd1 == -1)
        	return 1;
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);
	return (0);
}*/
