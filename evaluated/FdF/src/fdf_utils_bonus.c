/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:36:32 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/12 10:36:39 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move_up(t_MAP *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->dots[y][x].pos_y -= 50;
			x++;
		}
		y++;
	}
}

void	move_down(t_MAP *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->dots[y][x].pos_y += 50;
			x++;
		}
		y++;
	}
}

void	move_left(t_MAP *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->dots[y][x].pos_x -= 50;
			x++;
		}
		y++;
	}
}

void	move_right(t_MAP *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->dots[y][x].pos_x += 50;
			x++;
		}
		y++;
	}
}
