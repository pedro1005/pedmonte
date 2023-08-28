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
}*/

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

/*   
    draw_line(&dots[0][0],&dots[0][1] , map->mlx, map->win, 0x00FF00);
    draw_line(&dots[0][0],&dots[1][0] , map->mlx, map->win, 0x00FF00);
    draw_line(&dots[1][0],&dots[1][1] , map->mlx, map->win, 0x00FF00);
    draw_line(&dots[1][1],&dots[0][1] , map->mlx, map->win, 0x00FF00);
    */