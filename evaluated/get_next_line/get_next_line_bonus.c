/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:19:15 by pedmonte          #+#    #+#             */
/*   Updated: 2023/05/31 16:21:04 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

/*Read data from fd and updates static_data when finds \n or EOF*/
char	*update_data(int fd, char *static_data)
{
	ssize_t	read_fd;
	char	*buff;

	read_fd = 1;
	while (!find_char(static_data, '\n') && read_fd != 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		read_fd = read(fd, buff, BUFFER_SIZE);
		if (read_fd == -1 || buff == NULL)
		{
			free(static_data);
			free(buff);
			return (NULL);
		}
		buff[read_fd] = '\0';
		static_data = str_join(static_data, buff);
		free(buff);
	}
	if ((read_fd == 0 && !static_data[0]) || fd >= N_FILES)
	{
		free(static_data);
		return (NULL);
	}
	return (static_data);
}

char	*line_cpy(char *line, char *static_data)
{
	size_t	i;

	i = -1;
	while ((static_data)[++i])
	{
		line[i] = (static_data)[i];
		if ((static_data)[i] == '\n')
		{
			i++;
			break ;
		}
	}
	line[i] = '\0';
	return (line);
}

char	*update_line(char **static_data)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!(*static_data))
		return (NULL);
	while ((*static_data)[i] && (*static_data)[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	line = line_cpy(line, *static_data);
	if (!line[0])
	{
		free(line);
		free(*static_data);
		return (NULL);
	}
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
	static char	*static_data[N_FILES];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= N_FILES)
		return (NULL);
	if (!static_data[fd])
	{
		static_data[fd] = malloc(BUFFER_SIZE + 1);
		if (!static_data[fd])
			return (NULL);
		static_data[fd][0] = '\0';
	}
	static_data[fd] = update_data(fd, static_data[fd]);
	line = update_line(&static_data[fd]);
	static_data[fd] = cut_static_data(&static_data[fd], ft_strlen(line));
	return (line);
}

int	main(void)
{
	char	*line[N_FILES] = {NULL};
	int		fd1 ,fd2;

	fd1 = open("tests/bonus1.txt", O_RDONLY);
	fd2 = open("tests/bonus2.txt", O_RDONLY);
    		if (fd1 == -1 || fd2 == -1)
        return 1;
	line[fd1] = get_next_line(fd1);
	line[fd2] = get_next_line(fd2);
	while (line[fd1] && line[fd2])
	{
		printf("%s%s", line[fd1], line[fd2]);
		free(line[fd1]);
		free(line[fd2]);
		line[fd1] = get_next_line(fd1);
		line[fd2] = get_next_line(fd2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
