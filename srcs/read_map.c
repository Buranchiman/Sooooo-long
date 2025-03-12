/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranchiman <buranchiman@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:10:56 by wivallee          #+#    #+#             */
/*   Updated: 2025/03/12 12:05:20 by buranchiman      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_all_file(char *file_name, t_data *data)
{
	int		fd;
	char	buffer[1025];
	int		bytes_read;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_clean_exit(data, 1, "Cannot get fd");
	bytes_read = 1;
	data->buffer = NULL;
	while (bytes_read > 0)
	{
		ft_bzero(buffer, 1025);
		bytes_read = read(fd, buffer, 1024);
		data->buffer = ft_strjoinfree(data->buffer, buffer);
		if (bytes_read == -1 || data->buffer == NULL)
			ft_clean_exit(data, 1, "Fail in read or strjoin");
	}
}

void	check_borders(t_data *data, char **map)
{
	int				j;
	int				i;

	if (!is_all_c(map[0], '1'))
		ft_clean_exit(data, 1, "Missing outside wall");
	data->size = ft_strlen(map[0]);
	j = 1;
	while (map[j])
	{
		if (ft_strlen(map[j]) != data->size)
			ft_clean_exit(data, 1, "Map is not a rectangle");
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
		{
			ft_clean_exit(data, 1, "Missing outside wall");
		}
		i = 0;
		while (map[j][i])
		{
			if (!ft_strchr("01CEP", map[j][i]))
				ft_clean_exit(data, 1, "Map char unvalid");
			i++;
		}
		j++;
	}
}

void	check_elems(t_data *data, char **map, int count[3])
{
	int	i;
	int	j;

	j = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				count[0]++;
			if (map[j][i] == 'E')
				count[1]++;
			if (map[j][i] == 'P')
				count[2]++;
			i++;
		}
		j++;
	}
	data->nb = j;
}

void	check_map(t_data *data, char **map)
{
	int	count[3];

	check_borders(data, map);
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	check_elems(data, map, count);
	if (count[0] < 1 || count[1] != 1 || count[2] != 1)
		ft_clean_exit(data, 1, "Incorrect number of elems");
	data->items = count[0];
}

void	get_map(t_data *data, char *file_name)
{
	init_variables(data);
	read_all_file(file_name, data);
	data->map = ft_split(data->buffer, '\n');
	if (!data->map)
	{
		perror("Error\n");
		free(data->buffer);
		exit(EXIT_FAILURE);
	}
	check_map(data, data->map);
	fetch_player(data);
	data->count = 0;
	if (!searching_path(data, data->y, data->y))
	{
		perror("Error\n");
		free(data->buffer);
		free(data->map);
		exit(EXIT_FAILURE);
	}
	ft_clear_tab(data->map);
	data->count = 0;
}
