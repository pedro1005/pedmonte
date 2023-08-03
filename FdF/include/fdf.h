#ifndef FDF_H
# define FDF_H

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

typedef struct dot{
    int pos_x;
    int pos_y;
    int pos_z;
    int color;
    struct dot *next;
} DOT;

typedef DOT *P_DOT;

#endif
