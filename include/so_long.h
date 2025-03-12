#ifndef SO_LONG_H
# define SO_LONG_H

# include "ultralibft.h"
# include "mlx.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

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
	int				moves;
	int				vector[2];
	void			*mlx;
	void			*win;
	int				frame_count;
	void			*ground[2];
	void			*tree[2];
	void			*exit[3];
	void			*collectible;
	void			*player[2];
}				t_data;

void	check_file_format(char *file);

void	read_all_file(char *file_name, t_data *data);
void	check_borders(t_data *data, char **map);
void	check_elems(t_data *data, char **map, int count[3]);
void	check_map(t_data *data, char **map);
void	get_map(t_data *data, char *file_name);

int		searching_path(t_data *data, unsigned int y, unsigned int x);

void	init_variables(t_data *data);
void	verify_mlx(t_data *data);
int		start_mlx(t_data *data);

void	moving(int keycode, t_data *data);
int		key_hook(int keycode, t_data* data);

void	clear_img(t_data *data, void **img_tab, int tab_size);
void	ft_clean_exit(t_data *data, int option, char *msg);
int		handle_exit(t_data *data);

void	display_image(t_data *data, char c, int x, int y);
void	render(t_data *data);
int 	loop_hook(t_data *data);

int		is_all_c(char *string, char c);
void	fetch_player(t_data *data);

#endif
