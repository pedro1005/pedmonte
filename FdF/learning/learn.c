#include "../include/learn.h"

int	ft_sqrt(double nb)
{
	long	res;
	long	counter;

	res = 1;
	counter = 1;
	if (nb == 1)
		return (1);
	while (nb >= res && nb >= 0)
	{
		res = counter * counter;
		if (res == nb)
			return (counter);
		counter++;
	}
	return (0);
}

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

int main()
{
    void    *mlx = mlx_init();
    void    *win = mlx_new_window(mlx, 640, 640, "Learning...Draw line");
    
    draw_line(mlx, win, 0, 640, 0, 640, 0xFF0000);
    mlx_loop(mlx);
}