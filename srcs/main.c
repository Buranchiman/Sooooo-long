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

void	ft_clean_exit(t_data *data, int option, char *msg)
{
	if (data->map)
		ft_clear_tab(data->map);
	if (data->buffer)
		free(data->buffer);
	if (msg)
		ft_printf(2, "Error\n%s\n", msg);
	if (option == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	display_image(t_data *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->ground, x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->tree, x * 64, y * 64);
}

void	render(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			display_image(data, data->map[j][i], i, j);
			i++;
		}
		j++;
	}
}

// Loop function that updates every N frames
int loop_hook(t_data *data)
{
    data->frame_count++;

    if (data->frame_count >= 10) // Adjust this value to control speed
    {
        render(data);
        data->frame_count = 0; // Reset frame counter
    }
    return (0);
}

int	start_mlx(t_data  *data)
{
	int	stock;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 64 * data->size, 64 * data->nb, "crampte");
	data->ground = mlx_xpm_file_to_image(data->mlx, "img/ground64.xpm", &stock, &stock);
	data->tree = mlx_xpm_file_to_image(data->mlx, "img/tree64.xpm", &stock, &stock);
	return (0);
}

int	main(int arc, char **arv)
{
	t_data	data;

	if (arc == 1)
		return (0);
	if (arc > 2)
	{
		ft_printf(2, "Error\n");
		exit(EXIT_FAILURE);
	}
	check_file_format(arv[1]);
	get_map(&data, arv[1]);
	free(data.map);
	data.map = ft_split(data.buffer, '\n');
	free(data.buffer);
	if (!data.map)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	start_mlx(&data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
	ft_clean_exit(&data, 0, NULL);
	return (0);
}
