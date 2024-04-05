/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:37:28 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/02 19:07:27 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_imgs(t_game *game)
{
	game->tex.p_up = mlx_load_png("./pngs/ninja4.png");
	if (!game->tex.p_up)
		print_error(10);
	game->tex.p_do = mlx_load_png("./pngs/ninja.png");
	if (!game->tex.p_do)
		print_error(10);
	game->tex.p_left = mlx_load_png("./pngs/ninja3.png");
	if (!game->tex.p_left)
		print_error(10);
	game->tex.p_right = mlx_load_png("./pngs/ninja2.png");
	if (!game->tex.p_right)
		print_error(10);
	game->img.p_up = mlx_texture_to_image(game->mlx, game->tex.p_up);
	if (!game->img.p_up)
		print_error(10);
	game->img.p_do = mlx_texture_to_image(game->mlx, game->tex.p_do);
	if (!game->img.p_do)
		print_error(10);
	game->img.p_left = mlx_texture_to_image(game->mlx, game->tex.p_left);
	if (!game->img.p_left)
		print_error(10);
	game->img.p_right = mlx_texture_to_image(game->mlx, game->tex.p_right);
	if (!game->img.p_right)
		print_error(10);
	player_del_texture(game);
}

mlx_image_t	*player_img_direction(t_game *game, t_direction direction)
{
	mlx_image_t	*image;

	image = NULL;
	if (direction == UP)
		image = game->img.p_up;
	else if (direction == DOWN)
		image = game->img.p_do;
	else if (direction == LEFT)
		image = game->img.p_left;
	else if (direction == RIGHT)
		image = game->img.p_right;
	return (image);
}

void	player_del_texture(t_game *game)
{
	mlx_delete_texture(game->tex.p_up);
	mlx_delete_texture(game->tex.p_do);
	mlx_delete_texture(game->tex.p_left);
	mlx_delete_texture(game->tex.p_right);
}

void	enemy_del_texture(t_game *game)
{
	mlx_delete_texture(game->tex.x_up);
	mlx_delete_texture(game->tex.x_do);
	mlx_delete_texture(game->tex.x_left);
	mlx_delete_texture(game->tex.x_right);
}
