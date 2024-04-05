/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:36:31 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/02 19:24:38 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_enemies(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == 'X')
			{
				game->enemy[i].x = x;
				game->enemy[i].y = y;
				game->enemy[i].frame_skip = 50;
				game->enemy[i].under = '0';
				i++;
			}
			x++;
		}
		y++;
	}
}

void	enemy_imgs(t_game *game)
{
	game->tex.x_up = mlx_load_png("./pngs/rep2.png");
	if (!game->tex.x_up)
		print_error(10);
	game->tex.x_do = mlx_load_png("./pngs/rep1.png");
	if (!game->tex.x_do)
		print_error(10);
	game->tex.x_left = mlx_load_png("./pngs/rep3.png");
	if (!game->tex.x_left)
		print_error(10);
	game->tex.x_right = mlx_load_png("./pngs/rep4.png");
	if (!game->tex.x_right)
		print_error(10);
	game->img.x_up = mlx_texture_to_image(game->mlx, game->tex.x_up);
	if (!game->img.x_up)
		print_error(10);
	game->img.x_do = mlx_texture_to_image(game->mlx, game->tex.x_do);
	if (!game->img.x_do)
		print_error(10);
	game->img.x_left = mlx_texture_to_image(game->mlx, game->tex.x_left);
	if (!game->img.x_left)
		print_error(10);
	game->img.x_right = mlx_texture_to_image(game->mlx, game->tex.x_right);
	if (!game->img.x_right)
		print_error(10);
	enemy_del_texture(game);
}

void	enemy_hook(void *param)
{
	int		i;
	t_game	*game;

	game = (t_game *) param;
	i = 0;
	while (i < game->nx)
	{
		if (game->enemy[i].frame_skip == 0)
		{
			enemy_move(game, &game->enemy[i]);
			game->enemy[i].frame_skip = 30 + rand() % 30;
		}
		game->enemy[i].frame_skip--;
		i++;
	}
}

void	enemy_move(t_game *game, t_enemy *e)
{
	mlx_image_t	*image;
	t_direction	direction;

	direction = rand() % 4;
	image = enemy_img_direction(game, direction);
	game->map[e->y][e->x] = e->under;
	if (mlx_image_to_window(game->mlx, game->img.gr, e->x * P, e->y * P) < 0)
		print_error (10);
	if (e->under == 'C')
		if (mlx_image_to_window(game->mlx, game->img.c, e->x * P, e->y * P) < 0)
			print_error (10);
	if (direction == UP && e_move_check(game, e->y - 1, e->x))
		e->y--;
	else if (direction == DOWN && e_move_check(game, e->y + 1, e->x))
		e->y++;
	else if (direction == LEFT && e_move_check(game, e->y, e->x - 1))
		e->x--;
	else if (direction == RIGHT && e_move_check(game, e->y, e->x + 1))
		e->x++;
	if (mlx_image_to_window(game->mlx, image, e->x * P, e->y * P) < 0)
		print_error (10);
	if (e->x == game->px && e->y == game->py)
		end_game(game, LOSE);
	e->under = game->map[e->y][e->x];
	game->map[e->y][e->x] = 'X';
}

mlx_image_t	*enemy_img_direction(t_game *game, t_direction direction)
{
	mlx_image_t	*image;

	image = NULL;
	if (direction == UP)
		image = game->img.x_up;
	else if (direction == DOWN)
		image = game->img.x_do;
	else if (direction == LEFT)
		image = game->img.x_left;
	else if (direction == RIGHT)
		image = game->img.x_right;
	return (image);
}
