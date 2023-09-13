/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:54 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/12 10:38:02 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line_to_image(t_DOT *a, t_DOT *b, t_MAP *map)
{
	int	x;
	int	y;

	map->color = b->color;
	b->deltax = abs((int)(b->pos_x + 0.5) - (int)(a->pos_x + 0.5));
	b->deltay = abs((int)(b->pos_y + 0.5) - (int)(a->pos_y + 0.5));
	map->error = b->deltax - b->deltay;
	x = (int)(a->pos_x + 0.5);
	y = (int)(a->pos_y + 0.5);
	while (1)
	{
		bresenham(map, x, y);
		if (x == (int)(b->pos_x + 0.5) && y == (int)(b->pos_y + 0.5))
			break ;
		map->error2 = 2 * map->error;
		if (map->error2 > -b->deltay)
			x = x_update(map, a, b, x);
		if (map->error2 < b->deltax)
			y = y_update(map, a, b, y);
	}
}

char	*get_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		free(line);
		close(fd);
		exit(1);
	}
	return (line);
}

void	free_points(char **points, t_MAP *map)
{
	int	i;

	i = 0;
	while (points[map->width])
		map->width++;
	while (points[i])
	{
		free(points[i]);
		i++;
	}
	free(points);
}

void	set_size_map(t_MAP *map)
{
	float	delta_x;
	float	delta_y;

	delta_x = W_WIDTH / (map->width * 4);
	delta_y = W_HEIGHT / (map->height * 2);
	map->edge = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	if (map->edge < 1)
		map->edge = 0.8;
}

void	size_map(int fd, t_MAP *map)
{
	char	*line;
	char	**points;

	if (fd < 0 || map == NULL)
	{
		free(map);
		return ;
	}
	line = get_line(fd);
	map->height = 1;
	map->width = 0;
	points = ft_split(line, ' ');
	free_points(points, map);
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	set_size_map(map);
	free(line);
	close(fd);
	return ;
}
