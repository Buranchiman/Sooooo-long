#ifndef SO_LONG_H
# define SO_LONG_H

# include "ultralibft.h"
# include "mlx.h"

void	check_file_format(char *file);

char	*read_all_file(char *file_name);
int		is_all_c(char *string, char c);
void	error_management(char **map, int option);
void	check_borders(char **map);
void	check_map(char **map);
char	**get_map(char *file_name);

#endif
