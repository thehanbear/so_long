/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:37:36 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/02 19:23:41 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "../Libft/libft.h" 
# include "../MLX42/include/MLX42/MLX42.h"

# define P 32

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef enum end_type
{
	PAUSE,
	WIN,
	LOSE,
}	t_end_type;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_direction;

typedef struct s_texture
{
	mlx_texture_t	*p_up;
	mlx_texture_t	*p_do;
	mlx_texture_t	*p_left;
	mlx_texture_t	*p_right;
	mlx_texture_t	*x_up;
	mlx_texture_t	*x_do;
	mlx_texture_t	*x_left;
	mlx_texture_t	*x_right;
	mlx_texture_t	*wall;
	mlx_texture_t	*gr;
	mlx_texture_t	*c;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit2;
	mlx_texture_t	*win;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*p_up;
	mlx_image_t	*p_do;
	mlx_image_t	*p_left;
	mlx_image_t	*p_right;
	mlx_image_t	*x_up;
	mlx_image_t	*x_do;
	mlx_image_t	*x_left;
	mlx_image_t	*x_right;
	mlx_image_t	*wall;
	mlx_image_t	*gr;
	mlx_image_t	*c;
	mlx_image_t	*exit;
	mlx_image_t	*exit2;
	mlx_image_t	*win;
}	t_image;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		frame_skip;
	char	under;
}	t_enemy;

typedef struct s_game
{
	mlx_t		*mlx;
	t_texture	tex;
	t_image		img;
	t_end_type	status;
	t_enemy		*enemy;
	char		**map;
	char		*lines;
	char		**check;
	int			w;
	int			h;
	int			moves;
	int			exit;
	int			px;
	int			py;
	int			e_x;
	int			e_y;
	int			c_collected;
	int			np;
	int			nc;
	int			ne;
	int			nx;
	int			validity;
	int			counts;
}	t_game;

void		verify_map_name(char *file_name);
void		read_map(int fd, t_game *game);
int			main(int argc, char **argv);
void		check_walls(t_game *game);
void		validate_map(t_game *game);
void		read_error_free(char *line);
void		print_error(int type);
void		check_map(t_game *game, int y, int x);
void		is_it_rectangle(t_game *game);
void		valid_path(t_game *game, int y, int x);
void		init_param(t_game *game);
void		find_positions(t_game *game);
void		free_game(t_game *game);
void		get_the_lines(t_game *game);
char		*strjoin_free(char *s1, char *s2);
int32_t		about_mlx(t_game *game);
void		load_imgs(t_game *game);
void		convert_to_imgs(t_game *game);
void		my_hook(mlx_key_data_t keydata, void *param);
void		display_imgs(t_game *game);
mlx_image_t	*player_img_direction(t_game *game, t_direction direction);
void		player_imgs(t_game *game);
void		player_move(t_game *game, t_direction direction);
void		draw_imgs(t_game *game, int x, int y);
void		print_moves(t_game *game);
void		lock_e(t_game *game);
void		unlock_e(t_game *game);
void		collecting(t_game *game);
void		end_game(t_game *game, t_end_type end_type);
void		wait_for_esc(mlx_key_data_t keydata, void *param);
void		enemy_imgs(t_game *game);
void		enemy_move(t_game *game, t_enemy *e);
void		enemy_hook(void *param);
mlx_image_t	*enemy_img_direction(t_game *game, t_direction direction);
void		find_enemies(t_game *game);
void		player_del_texture(t_game *game);
void		enemy_del_texture(t_game *game);
bool		e_move_check(t_game *game, int y, int x);

#endif