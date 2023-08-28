#include "../include/fdf.h"
#include "../libft/libft.h"

void map_init(MAP *map)
{
    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, W_WIDTH, W_HEIGHT, "FdF - pedmonte");
    map->image = mlx_new_image(map->mlx, W_WIDTH, W_HEIGHT);
    
    if(!map->mlx || !map->win || !map->image)
        return ;
    
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char    *filename = argv[1];
        int fd;
        MAP *map;
        int pixel_bits;
        int line_bytes;
        int endian;
        int color = 0xAAAAAA;

        map = (MAP *)malloc(sizeof(MAP));
        if (map == NULL)
            exit(1);
        map_init(map);
        map->image_buffer = mlx_get_data_addr(map->image, &pixel_bits, &line_bytes, &endian);
        if (!map->image_buffer)
            exit(1);
        fd = open(filename, O_RDONLY);
        read_map(map, fd, filename);
        printf("read map() succed\n");//test
        if (map->dots == NULL) {
            free(map);
            printf("Error reading file\n");
            exit(1);
        }
        if (pixel_bits != 32)
            color = mlx_get_color_value(map->mlx, color);
        draw_lines2D_image(map, pixel_bits, endian, color);
        mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
        mlx_hook(map->win,17, 0, close_window, map);
        mlx_loop(map->mlx);
        return (0);
    }
    else
    {
        printf("Invalid Arguments\n");
        exit(1);
    }
}