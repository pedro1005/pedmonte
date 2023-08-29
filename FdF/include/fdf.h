#ifndef FDF_H
# define FDF_H


#ifndef W_WIDTH
# define W_WIDTH 800
#endif

#ifndef W_HEIGHT
# define W_HEIGHT 600
#endif

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../libft/libft.h"
#include "../include/keys.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dot{
    float pos_x;
    float pos_y;
    float pos_z;
    int color;
} DOT;

typedef struct map{
    int width;
    int height;
    DOT **dots;
    float   edge;
    int pixel_bits;
    int line_bytes;
    int endian;

    void    *mlx;
    void    *win;
    void    *image;
    char    *image_buffer;
} MAP;

void size_map(int fd, MAP *map);
void    read_map(MAP *map, int fd, char *filename);
void draw_line_to_image(DOT *a, DOT *b, char *image_buffer, int pixel_bits, int endian, int color);
void draw_lines2D_image(MAP *map, int pixel_bits, int endian, int color);
int close_window(MAP *map);
void map_init(MAP *map);
int	key_hook(int keycode, MAP *map);
void move_up(MAP *map);
void move_down(MAP *map);
void move_left(MAP *map);
void move_right(MAP *map);
void zoom_in(MAP *map);


#endif