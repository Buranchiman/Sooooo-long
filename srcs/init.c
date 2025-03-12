/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranchiman <buranchiman@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:37:07 by wivallee          #+#    #+#             */
/*   Updated: 2025/03/12 12:14:52 by buranchiman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_data *data)
{
	int	i;

	i = 0;
	data->frame_count = 0;
	data->moves = 0;
	data->buffer = NULL;
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->collectible = NULL;
	while (i < 2)
	{
		data->exit[i] = NULL;
		data->player[i] = NULL;
		data->ground[i] = NULL;
		data->tree[i] = NULL;
		i++;
	}
	data->exit[i] = NULL;
}

void	verify_mlx(t_data *data)
{
	int	i;

	i = 0;
	if (!data->collectible)
		ft_clean_exit(data, 1, "An mlx function failed");
	while (i < 2)
	{
		if (!data->ground[i] || !data->tree[i]
			|| !data->exit[i] || !data->player[i])
			ft_clean_exit(data, 1, "An mlx function failed");
		i++;
	}
	if (!data->exit[i])
		ft_clean_exit(data, 1, "An mlx function failed");
}

void	start_images(t_data *data)
{
	int	stock;

	data->collectible = mlx_xpm_file_to_image(data->mlx,
			"img/collectible.xpm", &stock, &stock);
	data->ground[0] = mlx_xpm_file_to_image(data->mlx,
			"img/ground64.xpm", &stock, &stock);
	data->ground[1] = mlx_xpm_file_to_image(data->mlx,
			"img/grass.xpm", &stock, &stock);
	data->tree[0] = mlx_xpm_file_to_image(data->mlx,
			"img/tree64.xpm", &stock, &stock);
	data->tree[1] = mlx_xpm_file_to_image(data->mlx,
			"img/green_tree.xpm", &stock, &stock);
	data->player[0] = mlx_xpm_file_to_image(data->mlx,
			"img/character.xpm", &stock, &stock);
	data->player[1] = mlx_xpm_file_to_image(data->mlx,
			"img/happy_player.xpm", &stock, &stock);
	data->exit[0] = mlx_xpm_file_to_image(data->mlx,
			"img/exit.xpm", &stock, &stock);
	data->exit[1] = mlx_xpm_file_to_image(data->mlx,
			"img/blocked_exit.xpm", &stock, &stock);
	data->exit[2] = mlx_xpm_file_to_image(data->mlx,
			"img/opened_exit.xpm", &stock, &stock);
}

int	start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_clean_exit(data, 1, "Starting mlx failed");
	data->win = mlx_new_window(data->mlx,
			64 * data->size, 64 * data->nb, "crampte");
	if (!data->win)
		ft_clean_exit(data, 1, "Creating mlx window failed");
	start_images(data);
	verify_mlx(data);
	return (0);
}
