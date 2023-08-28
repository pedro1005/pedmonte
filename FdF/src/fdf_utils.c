#include "../include/fdf.h"
#include "../libft/libft.h"

void draw_lines2D_image(MAP *map, int pixel_bits, int endian, int color) {
    printf("pixel bits = %d\nendian = %d\ncolor = %d\n", pixel_bits, endian, color);
    if (map == NULL || map->dots == NULL)
        return ;

    int x, y;
    x = 0;
    y = 0;
    while (y < map->height) {
        x = 0;
        while (x < map->width) {
            if (x + 1 < map->width)
                draw_line_to_image(&map->dots[y][x], &map->dots[y][x + 1], map->image_buffer, pixel_bits, endian, color);
            if (y + 1 < map->height)
                draw_line_to_image(&map->dots[y][x], &map->dots[y + 1][x], map->image_buffer, pixel_bits, endian, color);
            x++;
        }
        y++;
    }
}

void draw_line_to_image(DOT *a, DOT *b, char *image_buffer, int pixel_bits, int endian, int color) {
    if (!a || !b)
        return;

    int x1 = (int)(a->pos_x + 0.5); // Convert floating-point x coordinate to integer
    int y1 = (int)(a->pos_y + 0.5); // Convert floating-point y coordinate to integer
    int x2 = (int)(b->pos_x + 0.5);
    int y2 = (int)(b->pos_y + 0.5);

    int deltaX = abs(x2 - x1); // Use abs to ensure positive values
    int deltaY = abs(y2 - y1);
    int x_i, y_i;

    if (x1 < x2)
        x_i = 1;
    else
        x_i = -1;

    if (y1 < y2)
        y_i = 1;
    else
        y_i = -1;

    int error = deltaX - deltaY;
    int x = x1;
    int y = y1;

    while (1) {
        int pixel = (y * W_WIDTH + x) * (pixel_bits / 8);  // Calculate the pixel position in the buffer
        if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT) {
            if (endian == 1) {
                // Big endian (Most significant byte first)
                image_buffer[pixel + 0] = (color >> 24);           // Alpha channel
                image_buffer[pixel + 1] = (color >> 16) & 0xFF;    // Red channel
                image_buffer[pixel + 2] = (color >> 8) & 0xFF;     // Green channel
                image_buffer[pixel + 3] = color & 0xFF;            // Blue channel
            } else if (endian == 0) {
                // Little endian (Least significant byte first)
                image_buffer[pixel + 0] = color & 0xFF;            // Blue channel
                image_buffer[pixel + 1] = (color >> 8) & 0xFF;     // Green channel
                image_buffer[pixel + 2] = (color >> 16) & 0xFF;    // Red channel
                image_buffer[pixel + 3] = (color >> 24);           // Alpha channel
            }
        }   

        // Bresenham's algorithm logic
        if (x == x2 && y == y2)
        {
            //printf("break at x: %d || y: %d\n", x, y);
            break;
        }

        int error2 = 2 * error;

        if (error2 > -deltaY) {
            error -= deltaY;
            x += x_i;
        }

        if (error2 < deltaX) {
            error += deltaX;
            y += y_i;
        }
        //printf("a.x: %d || a.y: %d\nb.x: %d || b.y: %d\n", x, y, x2, y2);
    }
}

void size_map(int fd, MAP *map) //Atribui valores a map.width e map.heigth
{
    printf("test sizemap, fd =%d\n", fd); // test print
    if (fd < 0 || map == NULL)
        return ;
    char    *line;
    char    **points;
    map->height = 0;
    map->width = 0;
    line = get_next_line(fd);
    if (line == NULL)
        return ;
    if (line != NULL)
    {
        map->height++;
        points = ft_split(line, ' ');
        while (points[map->width])
            map->width++;
        for (int i = 0; points[i]; i++) {
            free(points[i]);}
        free(points);
        free(line);
    }
    else
        {
            free(line);
            close(fd);
            return ;
        }
    while ((line = get_next_line(fd)) != NULL)
    {
        map->height++;
        free(line);
    }
    if ((2 * map->height) < map->width)
        map->edge = W_WIDTH / (map->width * 2);
    if ((2 * map->height) >= map->width)
        map->edge = W_HEIGHT / (map->height * 4);
    free(line);
    close(fd);
    return ;
}

void    read_map(MAP *map, int fd, char *filename) //Cria matriz de pontos (DOT) no map
{
    if (map == NULL || !fd || fd < 0)
        //close_window(map);
        exit(1) ;
    int x;
    int y;
    float x_i;
    float y_i;
    char    *line;
    char    **word;

    x = 0;
    y = 0;
    x_i = 0;
    
    size_map(fd, map);
    printf("sizemap succed!\n");
    printf("map edge: %f\nmap widht: %d\nmap height: %d\n", map->edge, map->width, map->height); //test print
    y_i = (float)((map->width) * map->edge);
    if (map->height > map->width)
        y_i = (float)((map->height) * map->edge / 2);
    map->dots = (DOT **)malloc(map->height * sizeof(DOT *));
    if (map->dots == NULL)
        return ;
    for (y = 0; y < map->height; y++) {
        map->dots[y] = (DOT*)malloc(map->width * sizeof(DOT)); // Allocate memory for each row of dots
        if (map->dots[y] == NULL) {
            free(map->dots[y]);
            return ;
        }
    }
    fd = open(filename, O_RDONLY); // added
    line = get_next_line(fd);
    if (line == NULL)
    {
        close(fd);
        free(line);
        return ;
    }
    y = 0;
    while (y < map->height)
    {
        x = 0; // Reset 'x' for each row of 'dots'
        word = ft_split(line, ' ');
        if (word == NULL)
        {  
            free(word);
            free(line);
            return ;
        }
        x_i = y * map->edge;
        y_i = y_i + (map->edge / 2);
        while (x < map->width)
        {
            //y_f = y_f +(EDGE / 2);
            map->dots[y][x].pos_x = ((float)((x * map->edge))) + x_i;
            map->dots[y][x].pos_z = (float)((ft_atoi(word[x])));
            map->dots[y][x].pos_y = y_i - ((float)((x * map->edge / 2))) - (map->dots[y][x].pos_z * (map->edge / 4));
            //printf("dots[%d][%d].x = %f\n",y, x, map->dots[y][x].pos_x);//test
            //printf("dots[%d][%d].y = %f\n",y, x, map->dots[y][x].pos_y);//test
            //printf("dots[%d][%d].z = %f\n",y, x, map->dots[y][x].pos_z);//test
            //printf("------------\n");
            free(word[x]);
            x++;
        }
        y++;
        free(line);
        //for (x = 0; x < map->width; x++) {
        //    free(word[x]);
        //}
        free(word);
        line = get_next_line(fd);
        if (line == NULL)
            return ;
    }
    free(line);
    close(fd);
}

int close_window(MAP *map) {
    
    // Free dots and map structures
    mlx_clear_window(map->mlx,map->win);
    mlx_destroy_window(map->mlx, map->win);
    //if (map->image_buffer)
    //    free(map->image_buffer);
    if (map->image)
        free(map->image);
    if (map->dots[0]) {
        for (int i = 0; i < map->height; i++) {
                free(map->dots[i]);
            }
        }
    free(map->mlx);
    map->mlx = NULL;
    free(map->dots);
    free(map);
    
    exit (0);
}