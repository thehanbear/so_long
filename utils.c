/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:08:24 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/19 15:06:10 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_param(t_game *game)
{
	game->wid = 0;
	game->hei = 0;
	game->move = 0;
	game->empty = 0;
	game->exit = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->c_collected = 0;
	game->validity = 0;
	game->np = 0;
	game->nc = 0;
	game->ne = 0;
}
