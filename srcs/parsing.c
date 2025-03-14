/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivallee <wivallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:10:29 by wivallee          #+#    #+#             */
/*   Updated: 2025/03/11 14:10:31 by wivallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_format(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (ft_strncmp(&file[i], ".ber", 5))
	{
		ft_printf(2, "Error\nMap file is not a .ber\n");
		exit(EXIT_FAILURE);
	}
}
