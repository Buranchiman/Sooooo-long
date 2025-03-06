#ifndef SO_LONG_H
# define SO_LONG_H

# include "ultralibft.h"
# include "mlx.h"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

typedef struct s_data
{
	unsigned int	nb;
	unsigned int	size;
	char			*name;
	char			**map;
	char			*buffer;
	int				x;
	int				y;
	int				items;
	int				count;
	void			*mlx;
	void			*win;
	int				frame_count;
	void			*ground;
	void			*grass;
	void			*tree;
	void			*exit;
	void			*collectible;
	void			*player;
}				t_data;

void	check_file_format(char *file);

void	read_all_file(char *file_name, t_data *data);
int		is_all_c(char *string, char c);
void	check_borders(t_data *data, char **map);
void	check_map(t_data  *data, char **map);
void	get_map(t_data  *data, char *file_name);

int		searching_path(t_data *data, unsigned int y, unsigned int x);

void	ft_clean_exit(t_data *data, int option, char *msg);

#endif
