/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:08:24 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/19 14:39:24 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_param (t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->move = 0;
	game->empty = 0;
	game->exit = 0;
	game->P_x = 0;
	game->P_y = 0;
	game->c_collected = 0;
	game->validity = 0;
	game->np = 0;
	game->nc = 0;
	game->ne = 0;
}

void	read_error_free(char *line)
{
	free(line);
	print_error(1);
}

void	print_error(int type)
{
	if (type == 1)
		write(1, "Error\nMap read error.\n", 23);
	if (type == 2)
		write(1, "Error\ninvalid map name.\n", 25);
	if (type == 3)
		write(1, "Error\nMap must be rectangular.\n", 32);
	if (type == 4)
		write(1, "Error\nEmpty line.\n", 19);
	if (type == 5)
		write(1, "Error\nMap must be surrounded by walls.\n", 40);
	if (type == 6)
		write(1, "Error\nMap must contain exactly 1 E, 1 P, and at least 1 C.\n", 60);
	if (type == 7)
		write(1, "Error\nMap contains invalid characters.\n", 40);
	if (type == 8)
		write(1, "Error\nMemory allocation error.\n", 21);
	if (type == 9)
		write(1, "Error\ninvalid map path.\n", 25);
	exit (1);
}
void	free_game(t_game *game)
{
	int i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		free(game->check[i]);
		i++;
	}
	free(game->map);
	free(game->check);
	free(game->lines);
	//free(game);
}