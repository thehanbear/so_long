/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:28:43 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/02 19:29:17 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (mlx_image_to_window(game->mlx, g, game->px * PX, game->py * PX) < 0)
		print_error (10);
	if (direction == UP && game->map[game->py - 1][game->px] != '1')
		game->py--;
	else if (direction == DOWN && game->map[game->py + 1][game->px] != '1')
		game->py++;
	else if (direction == LEFT && game->map[game->py][game->px - 1] != '1')
		game->px--;
	else if (direction == RIGHT && game->map[game->py][game->px + 1] != '1')
		game->px++;
	if (mlx_image_to_window(game->mlx, image, game->px * PX, game->py * PX) < 0)
		print_error (10);
	if (game->map[game->py][game->px] == 'C')
		collecting(game);
	if (game->map[game->py][game->px] == 'E')
		end_game(game, WIN);
	game->moves++;
	print_moves_shell(game);
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

	g = game->img.gr;
	w = game->img.win;
	win = "Wow, You win!!";
	if (end_type == WIN)
	{
		if (mlx_image_to_window(game->mlx, g, game->px * PX, game->py * PX) < 0)
			print_error (10);
		if (mlx_image_to_window(game->mlx, w, game->px * PX, game->py * PX) < 0)
			print_error (10);
		mlx_put_string(game->mlx, win, game->w * PX / 2, game->h * PX / 2);
	}
	mlx_key_hook(game->mlx, wait_for_esc, game);
}
