/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranchiman <buranchiman@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:11:11 by wivallee          #+#    #+#             */
/*   Updated: 2025/03/12 12:06:51 by buranchiman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_direction(int keycode, t_data *data)
{
	data->vector[0] = 0;
	data->vector[1] = 0;
	if (keycode == KEY_W && data->map[data->y - 1][data->x] != '1')
		data->vector[0]--;
	if (keycode == KEY_A && data->map[data->y][data->x - 1] != '1')
		data->vector[1]--;
	if (keycode == KEY_S && data->map[data->y + 1][data->x] != '1')
		data->vector[0]++;
	if (keycode == KEY_D && data->map[data->y][data->x + 1] != '1')
		data->vector[1]++;
}

void	moving(int keycode, t_data *data)
{
	get_direction(keycode, data);
	if (data->vector[0] || data->vector[1])
	{
		data->moves++;
		ft_printf(1, "\rNumber of moves is %d", data->moves);
		if (data->count == data->items
			&& (data->map[data->y][data->x + data->vector[1]] == 'E'
			|| data->map[data->y + data->vector[0]][data->x] == 'E'))
			ft_clean_exit(data, 0, "You won !");
		if (data->map[data->y][data->x + data->vector[1]] == 'C'
			|| data->map[data->y + data->vector[0]][data->x] == 'C')
			data->count++;
		if (data->map[data->y][data->x] == 'N')
			data->map[data->y][data->x] = 'E';
		else
			data->map[data->y][data->x] = '0';
		data->x += data->vector[1];
		data->y += data->vector[0];
		if (data->map[data->y][data->x] == 'E')
			data->map[data->y][data->x] = 'N';
		else
			data->map[data->y][data->x] = 'P';
	}
}

int	key_hook(int keycode, t_data *data)
{
	moving(keycode, data);
	if (keycode == KEY_ESC)
		exit(0);
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
	data.map = ft_split(data.buffer, '\n');
	if (!data.map)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	start_mlx(&data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, handle_exit, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
	ft_clean_exit(&data, 0, NULL);
	return (0);
}
