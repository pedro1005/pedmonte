#include "../include/fdf.h"
#include <stdio.h>
#include <stdlib.h>

/*
void draw_line(void *mlx, void *win, int beginX, int endX, int beginY, int endY, int color)
{
    // Bresenman's algorythm
    int deltaX = abs(endX - beginX);
    int deltaY = abs(endY - beginY);
    int x_i, y_i;

    if (beginX < endX)
        x_i = 1;
    else
        x_i = -1;

    if (beginY < endY)
        y_i = 1;
    else
        y_i = -1;

    int error = deltaX - deltaY;
    int x = beginX;
    int y = beginY;

    while (1)
    {
        mlx_pixel_put(mlx, win, x, y, color);
        
        if (x == endX && y == endY)
            break;

        int error2 = 2 * error;
        
        if (error2 > -deltaY)
        {
            error -= deltaY;
            x += x_i;
        }

        if (error2 < deltaX)
        {
            error += deltaX;
            y += y_i;
        }
    }
}
*/

void draw_line(DOT a, DOT b, void *mlx, void *win, int color)
{
    int deltaX = abs(b.pos_x - a.pos_x);
    int deltaY = abs(b.pos_y - a.pos_y);
    int x_i, y_i;

    if (a.pos_x < b.pos_x)
        x_i = 1;
    else
        x_i = -1;

    if (a.pos_y < b.pos_y)
        y_i = 1;
    else
        y_i = -1;

    int error = deltaX - deltaY;
    int x = a.pos_x;
    int y = a.pos_y;

    while (1)
    {
        mlx_pixel_put(mlx, win, x, y, color);
        
        if (x == b.pos_x && y == b.pos_y)
            break;

        int error2 = 2 * error;
        
        if (error2 > -deltaY)
        {
            error -= deltaY;
            x += x_i;
        }

        if (error2 < deltaX)
        {
            error += deltaX;
            y += y_i;
        }
    }
}

/*
void draw_isometric_square(void *mlx, void *win, int centerX, int centerY, int size, int color)
{
    // Calcular as coordenadas dos pontos do quadrado em perspetiva isométrica
    int x1 = centerX - size;
    int y1 = centerY;
    int x2 = centerX;
    int y2 = centerY - (size / 2);
    int x3 = centerX + size;
    int y3 = centerY;
    int x4 = centerX;
    int y4 = centerY + (size / 2);

    // Desenhar as arestas do quadrado em perspetiva isométrica
    draw_line(mlx, win, x1, x2, y1, y2, color); // Aresta superior esquerda
    draw_line(mlx, win, x2, x3, y2, y3, color); // Aresta superior direita
    draw_line(mlx, win, x1, x4, y1, y4, color); // Aresta inferior esquerda
    draw_line(mlx, win, x3, x4, y3, y4, color); // Aresta inferior direita
}
*/

int close_window(void *mlx_ptr, void *win_ptr)
{
    mlx_destroy_window(mlx_ptr, win_ptr);
    return(1);
}

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 640, "FdF - pedmonte");
/*
    // Tamanho do quadrado
    int size = 50;

    // Coordenadas do centro do primeiro quadrado
    int centerX1 = 175;
    int centerY1 = 225;

    // Desenhar os três quadrados seguidos na diagonal
    draw_isometric_square(mlx, win, centerX1, centerY1, size, 0xFF0000); // Cor vermelha (RGB: 255, 0, 0)
    draw_isometric_square(mlx, win, centerX1 + size, centerY1 - size / 2, size, 0x00FF00); // Cor verde (RGB: 0, 255, 0)
    draw_isometric_square(mlx, win, centerX1 + 2 * size, centerY1 - size, size, 0x0000FF); // Cor azul (RGB: 0, 0, 255)
*/
    
    DOT a, b;
    a.pos_x = 0;
    a.pos_y = 0;
    b.pos_x = 50;
    b.pos_y = 0;

    draw_line(a, b, mlx, win, 0x00FF00);
    mlx_hook(win, 17, 0, close_window, mlx);
    mlx_loop(mlx);
}


