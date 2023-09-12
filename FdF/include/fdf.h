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

#ifndef W_WIDTH
# define W_WIDTH 800
#endif

#ifndef W_HEIGHT
# define W_HEIGHT 600
#endif

#ifndef M_PI
# define M_PI (3.14159265358979323846)
#endif

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../libft/libft.h"
#include "../include/keys.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dot{
    float   pos_x;
    float   pos_y;
    float   pos_z;
    int     color;
    int     deltax;
    int     deltay;
} DOT;

typedef struct map{
    int     width;
    int     height;
    DOT     **dots;
    float   edge;
    int     pixel_bits;
    int     line_bytes;
    int     endian;
    int     color;
    int     pixel;
    int     error;
    int     error2;
    int     finish;
    float   x_i;
    float   y_i;
    float   center_x;
    float   center_y;

    void    *mlx;
    void    *win;
    void    *image;
    char    *image_buffer;
} MAP;

int     close_window(MAP *map);
void	map_init(MAP *map);
int     key_hook(int keycode, MAP *map);
void	map_loop(MAP *map);
void	move_up(MAP *map);
void	move_down(MAP *map);
void	move_left(MAP *map);
void	move_right(MAP *map);
void	zoom_loop(MAP *map, double cos_ang, double sin_ang);
void	zoom_in(MAP *map);
void	zoom_out(MAP *map);
void	rotate_loop(MAP *map, double cos_ang, double sin_ang);
void	rotate_right(MAP *map);
void	rotate_left(MAP *map);
void	draw_lines2d_image(MAP *map);
void	set_buffer(MAP *map);
void	bresenham(MAP *map, int x, int y);
int     x_update(MAP *map, DOT *a, DOT *b, int x);
int     y_update(MAP *map, DOT *a, DOT *b, int y);
void	draw_line_to_image(DOT *a, DOT *b, MAP *map);
char	*get_line(int fd);
void	free_points(char **points, MAP *map);
void	set_size_map(MAP *map);
void	size_map(int fd, MAP *map);
void	map_alloc(MAP *map);
char	**split_word(char *line, char c, MAP *map, int fd);
void	fill_values(MAP *map, char **word, int y, int x);
void	fill_map(MAP *map, char *line, int fd);
void	read_map(MAP *map, int fd, char *filename);

#endif
