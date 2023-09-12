#include "../include/fdf.h"

void	rotate_loop(MAP *map, double cos_ang, double sin_ang)
{
	int		x;
	int		y;
	float	translated_x;
	float	translated_y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			translated_x = map->dots[y][x].pos_x - map->center_x;
			translated_y = map->dots[y][x].pos_y - map->center_y;
			map->dots[y][x].pos_x = translated_x * cos_ang
				- translated_y * sin_ang;
			map->dots[y][x].pos_x += map->center_x;
			map->dots[y][x].pos_y = translated_x * sin_ang
				+ translated_y * cos_ang;
			map->dots[y][x].pos_y += map->center_y;
			x++;
		}
		y++;
	}
}

void	rotate_right(MAP *map)
{
	double	cos_ang;
	double	sin_ang;

	cos_ang = cos(5 * M_PI / 180);
	sin_ang = sin(5 * M_PI / 180);
	map->center_x = map->dots[map->height / 2][map->width / 2].pos_x;
	map->center_y = map->dots[map->height / 2][map->width / 2].pos_y;
	rotate_loop(map, cos_ang, sin_ang);
}

void	rotate_left(MAP *map)
{
	double	cos_ang;
	double	sin_ang;

	cos_ang = cos(-5 * M_PI / 180);
	sin_ang = sin(-5 * M_PI / 180);
	map->center_x = map->dots[map->height / 2][map->width / 2].pos_x;
	map->center_y = map->dots[map->height / 2][map->width / 2].pos_y;
	rotate_loop(map, cos_ang, sin_ang);
}
