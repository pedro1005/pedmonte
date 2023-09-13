/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:56:09 by pedmonte          #+#    #+#             */
/*   Updated: 2023/09/06 14:56:15 by pedmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef W_WIDTH
#  define W_WIDTH 1024
# endif

# ifndef W_HEIGHT
#  define W_HEIGHT 768
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include "../include/keys.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_dot{
	float	pos_x;
	float	pos_y;
	float	pos_z;
	int		color;
	int		deltax;
	int		deltay;
}	t_DOT;

typedef struct t_map{
	int		width;
	int		height;
	t_DOT	**dots;
	float	edge;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		color;
	int		pixel;
	int		error;
	int		error2;
	int		finish;
	float	x_i;
	float	y_i;
	float	center_x;
	float	center_y;

	void	*mlx;
	void	*win;
	void	*image;
	char	*image_buffer;
}	t_MAP;

int		close_window(t_MAP *map);
void	map_init(t_MAP *map);
int		key_hook(int keycode, t_MAP *map);
void	map_loop(t_MAP *map);
void	move_up(t_MAP *map);
void	move_down(t_MAP *map);
void	move_left(t_MAP *map);
void	move_right(t_MAP *map);
void	zoom_loop(t_MAP *map, double cos_ang, double sin_ang);
void	zoom_in(t_MAP *map);
void	zoom_out(t_MAP *map);
void	rotate_loop(t_MAP *map, double cos_ang, double sin_ang);
void	rotate_right(t_MAP *map);
void	rotate_left(t_MAP *map);
void	draw_lines2d_image(t_MAP *map);
void	set_buffer(t_MAP *map);
void	bresenham(t_MAP *map, int x, int y);
int		x_update(t_MAP *map, t_DOT *a, t_DOT *b, int x);
int		y_update(t_MAP *map, t_DOT *a, t_DOT *b, int y);
void	draw_line_to_image(t_DOT *a, t_DOT *b, t_MAP *map);
char	*get_line(int fd);
void	free_points(char **points, t_MAP *map);
void	set_size_map(t_MAP *map);
void	size_map(int fd, t_MAP *map);
void	map_alloc(t_MAP *map);
char	**split_word(char *line, char c, t_MAP *map, int fd);
void	fill_values(t_MAP *map, char **word, int y, int x);
void	fill_map(t_MAP *map, char *line, int fd);
void	read_map(t_MAP *map, int fd, char *filename);

#endif
