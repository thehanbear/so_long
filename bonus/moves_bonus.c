/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:37:20 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/02 19:28:14 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_RELEASE)
		player_move (game, UP);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_RELEASE)
		player_move (game, DOWN);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
		player_move (game, LEFT);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
		player_move (game, RIGHT);
}

void	player_move(t_game *game, t_direction direction)
{
	mlx_image_t	*image;
	mlx_image_t	*g;

	image = player_img_direction(game, direction);
	g = game->img.gr;
	if (mlx_image_to_window(game->mlx, g, game->px * P, game->py * P) < 0)
		print_error (10);
	if (direction == UP && game->map[game->py - 1][game->px] != '1')
		game->py--;
	else if (direction == DOWN && game->map[game->py + 1][game->px] != '1')
		game->py++;
	else if (direction == LEFT && game->map[game->py][game->px - 1] != '1')
		game->px--;
	else if (direction == RIGHT && game->map[game->py][game->px + 1] != '1')
		game->px++;
	if (mlx_image_to_window(game->mlx, image, game->px * P, game->py * P) < 0)
		print_error (10);
	if (game->map[game->py][game->px] == 'C')
		collecting(game);
	if (game->map[game->py][game->px] == 'E')
		end_game(game, WIN);
	if (game->map[game->py][game->px] == 'X')
		end_game(game, LOSE);
	game->moves++;
	print_moves(game);
}

void	collecting(t_game *game)
{
	game->c_collected++;
	game->map[game->py][game->px] = '0';
	if (game->nc == game->c_collected)
		unlock_e(game);
}

void	end_game(t_game *game, t_end_type end_type)
{
	mlx_image_t	*g;
	mlx_image_t	*w;
	char		*win;
	char		*fin;

	g = game->img.gr;
	w = game->img.win;
	win = "Wow, You win!!";
	fin = "Better luck next time!!";
	if (end_type == WIN)
	{
		if (mlx_image_to_window(game->mlx, g, game->px * P, game->py * P) < 0)
			print_error (10);
		if (mlx_image_to_window(game->mlx, w, game->px * P, game->py * P) < 0)
			print_error (10);
		mlx_put_string(game->mlx, win, game->w * P / 2, game->h * P / 2);
	}
	if (end_type == LOSE)
		mlx_put_string(game->mlx, fin, game->w * P / 2, game->h * P / 2);
	mlx_key_hook(game->mlx, wait_for_esc, game);
}

bool	e_move_check(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E')
		return (false);
	else if (game->map[y][x] == 'X')
		return (false);
	return (true);
}
