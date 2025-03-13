/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:26:35 by wivallee          #+#    #+#             */
/*   Updated: 2025/03/13 13:26:37 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_img(t_data *data, void **img_tab, int tab_size)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		if (img_tab[i])
		{
			mlx_destroy_image(data->mlx, img_tab[i]);
		}
		i++;
	}
}

void	ft_clean_exit(t_data *data, int option, char *msg)
{
	if (data->map)
		ft_clear_tab(data->map);
	if (data->buffer)
		free(data->buffer);
	if (data->collectible)
		mlx_destroy_image(data->mlx, data->collectible);
	clear_img(data, data->exit, 3);
	clear_img(data, data->ground, 2);
	clear_img(data, data->tree, 2);
	clear_img(data, data->player, 2);
	if (msg && option == 1)
		ft_printf(2, "Error\n%s\n", msg);
	if (msg && option == 0)
		ft_printf(1, "\n%s\n", msg);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (option == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

int	handle_exit(t_data *data)
{
	ft_clean_exit(data, 0, NULL);
	return (0);
}
