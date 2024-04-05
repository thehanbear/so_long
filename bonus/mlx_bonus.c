/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:37:14 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/02 19:24:00 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	about_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init((game->w * P), (game->h * P), "so_long", true);
	if (!game->mlx)
		print_error (10);
	load_imgs(game);
	convert_to_imgs(game);
	player_imgs(game);
	enemy_imgs(game);
	display_imgs(game);
	if (game->nx > 0)
	{
		game->enemy = calloc(game->nx, sizeof(t_enemy));
		if (!game->enemy)
			print_error (10);
		find_enemies(game);
		mlx_loop_hook(game->mlx, &enemy_hook, game);
	}
	mlx_key_hook(game->mlx, my_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

void	load_imgs(t_game *game)
{
	game->tex.gr = mlx_load_png("./pngs/ground.png");
	if (!game->tex.gr)
		print_error(10);
	game->tex.wall = mlx_load_png("./pngs/tree.png");
	if (!game->tex.wall)
		print_error(10);
	game->tex.exit = mlx_load_png("./pngs/tanuki.png");
	if (!game->tex.exit)
		print_error(10);
	game->tex.exit2 = mlx_load_png("./pngs/exit2.png");
	if (!game->tex.exit2)
		print_error(10);
	game->tex.c = mlx_load_png("./pngs/ramen.png");
	if (!game->tex.c)
		print_error(10);
	game->tex.win = mlx_load_png("./pngs/win.png");
	if (!game->tex.win)
		print_error(10);
}

void	convert_to_imgs(t_game *game)
{
	game->img.gr = mlx_texture_to_image(game->mlx, game->tex.gr);
	if (!game->img.gr)
		print_error(10);
	game->img.wall = mlx_texture_to_image(game->mlx, game->tex.wall);
	if (!game->img.wall)
		print_error(10);
	game->img.exit = mlx_texture_to_image(game->mlx, game->tex.exit);
	if (!game->img.exit)
		print_error(10);
	game->img.c = mlx_texture_to_image(game->mlx, game->tex.c);
	if (!game->img.c)
		print_error(10);
	game->img.exit2 = mlx_texture_to_image(game->mlx, game->tex.exit2);
	if (!game->img.exit2)
		print_error(10);
	game->img.win = mlx_texture_to_image(game->mlx, game->tex.win);
	if (!game->img.win)
		print_error(10);
	mlx_delete_texture(game->tex.gr);
	mlx_delete_texture(game->tex.wall);
	mlx_delete_texture(game->tex.exit);
	mlx_delete_texture(game->tex.c);
	mlx_delete_texture(game->tex.exit2);
	mlx_delete_texture(game->tex.win);
}

void	display_imgs(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			draw_imgs(game, x, y);
			x++;
		}
		y++;
	}
	lock_e(game);
}

void	draw_imgs(t_game *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx, game->img.gr, x * P, y * P) < 0)
		print_error (10);
	if (game->map[y][x] == 'P')
		if (mlx_image_to_window(game->mlx, game->img.p_do, x * P, y * P) < 0)
			print_error (10);
	if (game->map[y][x] == 'X')
		if (mlx_image_to_window(game->mlx, game->img.x_do, x * P, y * P) < 0)
			print_error (10);
	if (game->map[y][x] == 'E')
		if (mlx_image_to_window(game->mlx, game->img.exit, x * P, y * P) < 0)
			print_error (10);
	if (game->map[y][x] == 'C')
		if (mlx_image_to_window(game->mlx, game->img.c, x * P, y * P) < 0)
			print_error (10);
	if (game->map[y][x] == '1')
		if (mlx_image_to_window(game->mlx, game->img.wall, x * P, y * P) < 0)
			print_error (10);
}
