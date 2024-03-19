/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:09:57 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/19 15:07:21 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game, int y, int x)
{
	y = 0;
	while (y < game->hei)
	{
		x = 0;
		while (x < game->wid)
		{
			if (game->map[y][x] == 'P')
				game->np ++;
			else if (game->map[y][x] == 'C')
				game->nc ++;
			else if (game->map[y][x] == 'E')
				game->ne ++;
			else if (game->map[y][x] != '1' && game->map[y][x] != '0')
				print_error (7);
			x++;
		}
		y++;
	}
	if (game->np != 1 || game->ne != 1 || game->nc < 1)
		print_error (6);
}

void	check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->hei)
	{
		x = 0;
		while (x < game->wid)
		{
			if (y == 0 || y == game->hei - 1 || x == 0 || x == game->wid - 1)
			{
				if (game->map[y][x] != '1')
					print_error(5);
			}
			x++;
		}
		y++;
	}
}


void	is_it_rectangle(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != (size_t)game->wid)
			print_error (3);
		i++;
	}
	if (i != game->hei)
		print_error (4);
	len = ft_strlen(game->lines);
	if (game->lines[len -1] == '\n')
		print_error (4);
	free(game->lines);
}

void	valid_path(t_game *game, int y, int x)
{
	if (game->check[y][x] == 'E')
		game->exit++;
	if (game->check[y][x] == 'C')
		game->c_collected++;
	if (game->exit == 1 && game->nc == game->c_collected)
		game->validity = 1;
	game->check[y][x] = '1';
	if (game->check[y + 1][x] != '1')
		valid_path (game, y + 1, x);
	if (game->check[y - 1][x] != '1')
		valid_path (game, y - 1, x);
	if (game->check[y][x + 1] != '1')
		valid_path (game, y, x + 1);
	if (game->check[y][x - 1] != '1')
		valid_path (game, y, x - 1);
}

void	find_positions(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->hei)
	{
		x = 0;
		while (x < game->wid)
		{
			if (game->map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
			}
			x++;
		}
		y++;
	}
}