#include "so_long.h"

int main()
{
    void    *mlx;
    void    *win;
    void    *img;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "So_Long");
    mlx_loop(mlx);
}