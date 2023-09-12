#include "../include/fdf.h"

void	move_up(MAP *map)
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

void	move_down(MAP *map)
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

void	move_left(MAP *map)
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

void	move_right(MAP *map)
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
