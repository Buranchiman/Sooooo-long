/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranchiman <buranchiman@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:11:32 by wivallee          #+#    #+#             */
/*   Updated: 2025/03/12 12:05:35 by buranchiman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	searching_path(t_data *data, unsigned int y, unsigned int x)
{
	if (y >= data->nb || x >= data->size)
		return (0);
	if (data->count == data->items && data->map[y][x] == 'E')
		return (1);
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'C')
		data->count++;
	if (data->map[y][x] != 'E')
		data->map[y][x] = '1';
	if (searching_path(data, y, x + 1) == 1)
		return (1);
	if (searching_path(data, y + 1, x) == 1)
		return (1);
	if (searching_path(data, y, x - 1) == 1)
		return (1);
	if (searching_path(data, y - 1, x) == 1)
		return (1);
	return (0);
}
