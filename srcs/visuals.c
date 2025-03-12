#include "so_long.h"

void	show_nature(t_data *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->ground[1],
			x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->tree[1],
			x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player[1],
			x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit[2],
			x * 64, y * 64);
}

void	show_drougth(t_data *data, char c, int x, int y)
{
	if (c == 'N')
		mlx_put_image_to_window(data->mlx, data->win, data->exit[1],
			x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->ground[0],
			x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->tree[0],
			x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player[0],
			x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit[0],
			x * 64, y * 64);
}

void	display_image(t_data *data, char c, int x, int y)
{
	if (data->count == data->items)
		show_nature(data, c, x, y);
	else
		show_drougth(data, c, x, y);
}

void	render(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			display_image(data, data->map[j][i], i, j);
			if (data->map[j][i] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->collectible, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

int	loop_hook(t_data *data)
{
	data->frame_count++;
	if (data->frame_count >= 10)
	{
		render(data);
		data->frame_count = 0;
	}
	return (0);
}
