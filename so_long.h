
# ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./Libft/libft.h" 
# include "./MLX42/include/MLX42/MLX42.h"

# include <stdio.h>

typedef struct	s_game
{
	char 	**map;
	int		width;
	int		height;
	int		move;
	char	*lines;
}	t_game;

typedef struct	s_map
{
	int	empty;
	int	wall;
	int	collectible;
	int	exit;
	int	player;
}	t_map;

int		verify_map_name(const char *file_name, const char *ending);
void	*read_map(char *map, t_game *game);
int		main(int argc, char **argv);

#endif
