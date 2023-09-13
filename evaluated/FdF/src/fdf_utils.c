/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:23:21 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/03 18:23:36 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"

void	draw_lines2d_image(t_MAP *map)
{
	int	x;
	int	y;

	if (map == NULL || map->dots == NULL)
		return ;
	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x + 1 < map->width)
				draw_line_to_image(&map->dots[y][x], &map->dots[y][x + 1], map);
			if (y + 1 < map->height)
				draw_line_to_image(&map->dots[y][x], &map->dots[y + 1][x], map);
			x++;
		}
		y++;
	}
}

void	set_buffer(t_MAP *map)
{
	if (map->endian == 1)
	{
		map->image_buffer[map->pixel + 0] = (map->color >> 24);
		map->image_buffer[map->pixel + 1] = (map->color >> 16) & 0xFF;
		map->image_buffer[map->pixel + 2] = (map->color >> 8) & 0xFF;
		map->image_buffer[map->pixel + 3] = map->color & 0xFF;
	}
	else if (map->endian == 0)
	{
		map->image_buffer[map->pixel + 0] = map->color & 0xFF;
		map->image_buffer[map->pixel + 1] = (map->color >> 8) & 0xFF;
		map->image_buffer[map->pixel + 2] = (map->color >> 16) & 0xFF;
		map->image_buffer[map->pixel + 3] = (map->color >> 24);
	}
}

void	bresenham(t_MAP *map, int x, int y)
{
	map->pixel = (y * W_WIDTH + x) * (map->pixel_bits / 8);
	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
		set_buffer(map);
}

int	x_update(t_MAP *map, t_DOT *a, t_DOT *b, int x)
{
	map->error -= b->deltay;
	if (a->pos_x < b->pos_x)
		x += 1;
	else
		x -= 1;
	return (x);
}

int	y_update(t_MAP *map, t_DOT *a, t_DOT *b, int y)
{
	map->error += b->deltax;
	if (a->pos_y < b->pos_y)
		y += 1;
	else
		y -= 1;
	return (y);
}