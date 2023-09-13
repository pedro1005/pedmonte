/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:06 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/12 10:37:11 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	map_alloc(t_MAP *map)
{
	int	y;

	y = 0;
	map->dots = (t_DOT **)malloc(map->height * sizeof(t_DOT *));
	if (map->dots == NULL)
	{
		free(map);
		exit(1);
	}
	while (y < map->height)
	{
		map->dots[y] = (t_DOT *)malloc(map->width * sizeof(t_DOT));
		if (map->dots[y] == NULL)
		{
			free(map->dots);
			free(map);
			exit(1);
		}
		y++;
	}
}

char	**split_word(char *line, char c, t_MAP *map, int fd)
{
	char	**word;

	word = ft_split(line, c);
	if (word == NULL)
	{
		free(map);
		free(word);
		free(line);
		close(fd);
		exit(1);
	}
	return (word);
}

void	fill_values(t_MAP *map, char **word, int y, int x)
{
	char	**color;

	color = ft_split(word[x], ',');
	map->dots[y][x].pos_x = ((float)((x * map->edge))) + map->x_i;
	map->dots[y][x].pos_z = (float)((ft_atoi(word[x])));
	map->dots[y][x].pos_y = map->y_i - ((float)((x * map->edge / 2)))
		- (map->dots[y][x].pos_z * (map->edge / 4));
	if (color[1])
	{
		map->dots[y][x].color = ft_atoi_base(color[1] + 2, 16);
		free(color[0]);
		free(color[1]);
	}
	else
	{
		map->dots[y][x].color = 0xFFFFFF;
		free(color[0]);
		free(color[1]);
	}
	free(word[x]);
	free(color);
}

void	fill_map(t_MAP *map, char *line, int fd)
{
	char	**word;
	int		y;
	int		x;

	y = 0;
	while (y < map->height && line)
	{
		x = 0;
		word = split_word(line, ' ', map, fd);
		map->x_i = y * map->edge;
		map->y_i = map->y_i + (map->edge / 2);
		while (x < map->width)
		{
			fill_values(map, word, y, x);
			x++;
		}
		free(word[x]);
		y++;
		free(line);
		free(word);
		line = get_next_line(fd);
	}
}

void	read_map(t_MAP *map, int fd, char *filename)
{
	char	*line;

	map->x_i = 0;
	size_map(fd, map);
	map->y_i = (float)((map->height) * map->edge);
	if (map->height > map->width)
		map->y_i = (float)((map->height) * map->edge / 2);
	map_alloc(map);
	fd = open(filename, O_RDONLY);
	line = get_line(fd);
	fill_map(map, line, fd);
	close(fd);
}
