#include "so_long.h"

char	*read_all_file(char *file_name)
{
	int		fd;
	char	buffer[1025];
	char	*holder;
	int		bytes_read;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	bytes_read = 1;
	holder = NULL;
	while (bytes_read > 0)
	{
		ft_bzero(buffer, 1025);
		bytes_read = read(fd, buffer, 1024);
		holder = ft_strjoinfree(holder, buffer);
		if (bytes_read == -1 || holder == NULL)
		{
			perror("Error\n");
			if (holder)
				free(holder);
			exit(EXIT_FAILURE);
		}
	}
	return (holder);
}
int	is_all_c(char *string, char c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] != c)
			return (0);
		i++;
	}
	return (1);
}

void	error_management(char **map, int option)
{
	if (option == 0)
	{
		ft_printf(2, "Error\nMap content does not fit the requirements\n");
		ft_clear_tab(map);
		exit(EXIT_FAILURE);
	}
}

void	check_borders(char **map)
{
	int				j;
	unsigned int	length;
	int				i;

	if (!is_all_c(map[0], '1'))
		error_management(map, 0);
	length = ft_strlen(map[0]);
	j = 1;
	while (map[j])
	{
		if (ft_strlen(map[j]) != length)
			error_management(map, 0);
		if (map[j][0] != '1' || map[j][ft_strlen(map[j])] != '1')
			error_management(map, 0);
		i = 0;
		while (map[j][j])
		{
			if (!ft_strchr("01CEP", map[j][i]))
				error_management(map, 0);
			i++;
		}

		j++;
	}
}

void	check_map(char **map)
{
	int	i;
	int	j;
	int	count[3];

	check_borders(map);
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[i][j] == 'C')
				count[0]++;
			if (map[i][j] == 'E')
				count[1]++;
			if (map[i][j] == 'P')
				count[2]++;
			i++;
		}
		j++;
	}
	if (count[0] != 1 || count[1] != 1 || count[2] != 1)
		error_management(map, 0);
}

char	**get_map(char *file_name)
{
	char	**map;
	char	*file_data;

	file_data = read_all_file(file_name);
	map = ft_split(file_data, '\n');
	free(file_data);
	if (!map)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	check_map(map);
	return (map);
}
