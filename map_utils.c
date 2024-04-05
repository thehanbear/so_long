/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:28:25 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/03 17:52:02 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game, int y, int x)
{
	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
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
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (y == 0 || y == game->h - 1 || x == 0 || x == game->w - 1)
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
		if (ft_strlen(game->map[i]) != ((size_t)game->w))
			print_error (3);
		i++;
	}
	if (i != game->h)
		print_error (4);
	if (game->h > 400 || game->w > 800)
		print_error (10);
	len = ft_strlen(game->lines);
	if (game->lines[len - 1] == '\n')
		print_error (4);
}

void	valid_path(t_game *game, int y, int x)
{
	if (game->check[y + 1][x] == 'E' || game->check[y - 1][x] == 'E')
		game->exit = 1;
	if (game->check[y][x + 1] == 'E' || game->check[y][x - 1] == 'E')
		game->exit = 1;
	if (game->check[y][x] == 'C')
		game->c_collected++;
	if (game->exit == 1 && game->nc == game->c_collected)
		game->validity = 1;
	game->check[y][x] = '1';
	if (game->check[y + 1][x] != '1' && game->check[y + 1][x] != 'E')
		valid_path (game, y + 1, x);
	if (game->check[y - 1][x] != '1' && game->check[y - 1][x] != 'E')
		valid_path (game, y - 1, x);
	if (game->check[y][x + 1] != '1' && game->check[y][x + 1] != 'E')
		valid_path (game, y, x + 1);
	if (game->check[y][x - 1] != '1' && game->check[y][x - 1] != 'E')
		valid_path (game, y, x - 1);
}

void	find_positions(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
			}
			x++;
		}
		y++;
	}
}
