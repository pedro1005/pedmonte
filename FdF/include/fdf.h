#ifndef FDF_H
# define FDF_H


#ifndef W_WIDTH
# define W_WIDTH 1000
#endif

#ifndef W_HEIGHT
# define W_HEIGHT 1000
#endif

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../libft/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dot{
    float pos_x;
    float pos_y;
    float pos_z;
} DOT;

typedef struct map{
    int width;
    int height;
    DOT **dots;
    float   edge;

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


#endif