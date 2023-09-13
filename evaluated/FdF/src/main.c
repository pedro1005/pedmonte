/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:10:12 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/03 15:17:51 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"

int	close_window(t_MAP *map)
{
	int	i;

	i = 0;
	if (map->dots[0])
	{
		while (i < map->height)
		{
			free(map->dots[i]);
			i++;
		}
	}
	if (map->dots)
		free(map->dots);
	mlx_clear_window(map->mlx, map->win);
	if (map->image)
		mlx_destroy_image(map->mlx, map->image);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	free(map->mlx);
	free(map);
	exit (0);
}

void	map_init(t_MAP *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, W_WIDTH, W_HEIGHT, "FdF - pedmonte");
	map->image = mlx_new_image(map->mlx, W_WIDTH, W_HEIGHT);
	map->image_buffer = mlx_get_data_addr(map->image, &map->pixel_bits,
			&map->line_bytes, &map->endian);
	if (!map->image_buffer)
	{
		free(map);
		exit(1);
	}
	if (!map->mlx || !map->win || !map->image)
	{
		if (map->image)
			mlx_destroy_image(map->mlx, map->image);
		if (map->win)
			mlx_destroy_window(map->mlx, map->win);
		if (map->mlx)
			mlx_destroy_display(map->mlx);
		free(map);
		exit(1);
	}
}

int	key_hook(int keycode, t_MAP *map)
{
	if (keycode == ESC)
		close_window(map);
	mlx_destroy_image(map->mlx, map->image);
	map->image = mlx_new_image(map->mlx, W_WIDTH, W_HEIGHT);
	draw_lines2d_image(map);
	mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
	return (0);
}

void	map_loop(t_MAP *map)
{
	draw_lines2d_image(map);
	mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
	mlx_string_put(map->mlx, map->win, 10, 50, 0x00FFFF, "Press ESC to exit!");
	mlx_hook(map->win, KEY_PRESS_EVENT, 1, key_hook, map);
	mlx_hook(map->win, 17, 0, close_window, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char **argv)
{
	char	*filename;
	int		fd;
	t_MAP	*map;

	if (argc == 2)
	{
		filename = argv[1];
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			exit(1);
		map = (t_MAP *)malloc(sizeof(t_MAP));
		if (map == NULL)
			exit(1);
		map_init(map);
		read_map(map, fd, filename);
		if (map->dots == NULL)
		{
			free(map);
			exit(1);
		}
		map_loop(map);
		return (0);
	}
	exit(1);
}
