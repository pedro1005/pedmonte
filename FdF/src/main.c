#include "../include/fdf.h"

#include "../libft/libft.h"

void map_init(MAP *map)
{
    // Initialize the MAP structure members
    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, W_WIDTH, W_HEIGHT, "FdF - pedmonte");
    map->image = mlx_new_image(map->mlx, W_WIDTH, W_HEIGHT);
    
    // Check if initialization was successful
    if (!map->mlx || !map->win || !map->image)
    {
        // Free any allocated resources before exiting
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

void move_up(MAP *map)
{
    int   x;
    int y;

    x = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            map->dots[y][x].pos_y -= 50;
            x++;
        }
        y++;
    }
}

void move_down(MAP *map)
{
    int   x;
    int y;

    x = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            map->dots[y][x].pos_y += 50;
            x++;
        }
        y++;
    }
}

void move_left(MAP *map)
{
    int   x;
    int y;

    x = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            map->dots[y][x].pos_x -= 100;
            x++;
        }
        y++;
    }
}

void move_right(MAP *map)
{
    int   x;
    int y;

    x = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            map->dots[y][x].pos_x += 100;
            x++;
        }
        y++;
    }
}

void zoom_in(MAP *map)
{
    map->edge *= 1.5;
}

int	key_hook(int keycode, MAP *map)
{
	printf("keycode = %d\n", keycode);
	if (keycode == ESC)
		close_window(map);
    if (keycode == UP)
        move_up(map);
    if (keycode == DOWN)
        move_down(map);
    if (keycode == LEFT)
        move_left(map);
    if (keycode == RIGHT)
        move_right(map);
    if (keycode == PLUS_KEY)
        zoom_in(map);
    mlx_destroy_image(map->mlx, map->image);
    map->image = mlx_new_image(map->mlx, W_WIDTH, W_HEIGHT);
    draw_lines2D_image(map, map->pixel_bits, map->endian, 0xAAAAAA);
    mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
    
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char    *filename = argv[1];
        int fd;
        MAP *map;
        
        int color = 0xAAAAAA;

        map = (MAP *)malloc(sizeof(MAP));
        if (map == NULL)
            exit(1);
        map_init(map);
        map->image_buffer = mlx_get_data_addr(map->image, &map->pixel_bits, &map->line_bytes, &map->endian);
        if (!map->image_buffer)
        {  
            free(map);
            exit(1);
        }
        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            if (map->image)
                mlx_destroy_image(map->mlx, map->image);
            if (map->win)
                mlx_destroy_window(map->mlx, map->win);
            if (map->mlx)
                mlx_destroy_display(map->mlx);
            free(map->mlx);
            free(map);
            exit(1);
        }
        read_map(map, fd, filename);
        printf("read map() succed\n");//test
        if (map->dots == NULL) {
            free(map);
            printf("Error reading file\n");
            exit(1);
        }
        /*if (pixel_bits != 32)
            color = mlx_get_color_value(map->mlx, color);*/
        draw_lines2D_image(map, map->pixel_bits, map->endian, color);
        mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
        mlx_hook(map->win, KEY_PRESS_EVENT, 1, key_hook, map);
        //mlx_hook(map->win,17, 0, close_window, map);
        mlx_loop(map->mlx);
        return (0);
    }
    else
    {
        printf("Invalid Arguments\n");
        exit(1);
    }
}