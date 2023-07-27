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
    /*
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;

    //int pixels = ft_sqrt((deltaX * deltaX) + (deltaY * deltaY));

    int pixels = abs((int)deltaX) > abs((int)deltaY) ? abs((int)deltaX) : abs((int)deltaY);
    deltaX /= pixels;
    deltaY /= pixels;

    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
        mlx_pixel_put(mlx, win, (int)pixelX, (int)pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    */

   int  deltaX = endX - beginX;
   int  deltaY = endY - beginY;

}

int main()
{
    void    *mlx = mlx_init();
    void    *win = mlx_new_window(mlx, 640, 640, "Learning...Draw line");
    
    //mlx_pixel_put(mlx, win, 640/2, 640/2, 0xFF0000);
    draw_line(mlx, win, 0, 640, 0, 640, 0xFF0000);
    mlx_loop(mlx);
}