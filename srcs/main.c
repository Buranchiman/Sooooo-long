#include "so_long.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	key_hook_testing(int keycode)
// {
// 	if (keycode == 0xff1b)
// 		ft_printf(1, "key  hook working\n");
// 	return  (0);
// }

// int	loop_hook_testing(void *myStruct)
// {
// 	ft_printf(1, "rendering\n");
// 	return (0);
// }

// int main()
// {
// 	void	*mlx;
// 	void	*win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 1920, 1080, "So_Long");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_key_hook(win, key_hook_testing, NULL);
// 	mlx_loop_hook(mlx, loop_hook_testing, NULL);
// 	mlx_loop(mlx);
// 	return (0);
// }


int	main(int arc, char **arv)
{
	if (arc == 1)
		return (0);
	if (arc > 2)
	{
		ft_printf(2, "Error\n");
		exit(EXIT_FAILURE);
	}
	check_file_format(arv[1]);
	get_map(arv[1]);
	return (0);
}
