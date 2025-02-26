#include "so_long.h"

int	read_all_file(char *file_name)
{
	int		fd;
	char	buffer[1025];
	char	*holder;
	int		bytes_read;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	bytes_read = 1;
	ft_bzero(holder, 1025);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 1024);
	}
}
