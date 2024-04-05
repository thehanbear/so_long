/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:28:30 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/04/02 18:25:26 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_game *game)
{
	int		read_byte;
	char	*temp;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		print_error(1);
	line = malloc(sizeof(char));
	if (!line)
		print_error(8);
	line[0] = '\0';
	read_byte = BUFFER_SIZE;
	while (read_byte == BUFFER_SIZE)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			print_error(8);
		read_byte = read(fd, temp, BUFFER_SIZE);
		if (read_byte == -1)
			read_error_free(temp);
		temp[read_byte] = '\0';
		line = strjoin_free(line, temp);
	}
	game->lines = ft_strdup(line);
	free(line);
	get_the_lines(game);
}

void	get_the_lines(t_game *game)
{
	int	i;

	i = 0;
	game->h = 1;
	while (game->lines[i])
	{
		if (game->lines[i] == '\n')
			game->h++;
		i++;
	}
	game->map = ft_split(game->lines, '\n');
	game->w = ft_strlen(game->map[0]);
}

void	validate_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!game->map)
		print_error (1);
	is_it_rectangle(game);
	check_walls(game);
	check_map (game, y, x);
	game->check = ft_split(game->lines, '\n');
	find_positions(game);
	valid_path(game, game->py, game->px);
	game->c_collected = 0;
	if (game->validity != 1)
		print_error (9);
}

void	verify_map_name(char *file_name)
{
	int		i;
	int		j;
	char	*type;

	i = ft_strlen(file_name) - 4;
	j = 0;
	type = ".ber";
	while (file_name[i])
	{
		if (file_name[i] != type[j])
			print_error(2);
		i++;
		j++;
	}
}
