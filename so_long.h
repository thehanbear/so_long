
# ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./Libft/libft.h" 
# include "./MLX42/include/MLX42/MLX42.h"

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct	s_game
{
	char 	**map;
	char	*lines;
	char	**check;
	int		width;
	int		height;
	int		move;
	int		empty;
	int		exit;
	int		P_x;
	int		P_y;
	int		c_collected;
	int 	np;
	int 	nc;
	int		ne;
	int		validity;
}	t_game;


void	verify_map_name(const char *file_name, const char *ending);
void	read_map(int fd, t_game *game);
int		main(int argc, char **argv);
void 	check_walls (t_game *game);
void	validate_map (t_game *game);
void	read_error_free(char *line);
void	print_error(int type);
void 	check_map (t_game *game, int y, int x);
void	is_it_rectangle(t_game *game);
void	valid_path(t_game *game, int y, int x);
void	init_param (t_game *game);
void	find_positions(t_game *game);
void 	copy_map(t_game *game);
void	free_game(t_game *game);
void	get_the_lines(t_game *game);

#endif
