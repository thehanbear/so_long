/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:29:08 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/03 17:25:04 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_param(t_game *game)
{
	game->w = 0;
	game->h = 0;
	game->moves = 0;
	game->exit = 0;
	game->px = 0;
	game->py = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->c_collected = 0;
	game->validity = 0;
	game->np = 0;
	game->nc = 0;
	game->ne = 0;
}

void	print_moves_shell(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	free(moves);
}

void	lock_e(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == 'E')
			{
				game->e_x = x;
				game->e_y = y;
				game->map[y][x] = '1';
			}
			x++;
		}
		y++;
	}
}

void	unlock_e(t_game *game)
{
	int	x;
	int	y;

	x = game->e_x;
	y = game->e_y;
	game->map[y][x] = 'E';
	if (mlx_image_to_window(game->mlx, game->img.gr, x * PX, y * PX) < 0)
		print_error (10);
	if (mlx_image_to_window(game->mlx, game->img.exit2, x * PX, y * PX) < 0)
		print_error (10);
}

void	wait_for_esc(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}
