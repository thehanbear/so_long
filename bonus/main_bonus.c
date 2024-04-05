/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:36:50 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/02 19:09:23 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	game = malloc(sizeof(t_game));
	if (argc != 2)
		print_error(1);
	init_param(game);
	verify_map_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	read_map(fd, game);
	close (fd);
	validate_map(game);
	about_mlx(game);
	free_game(game);
	return (0);
}
