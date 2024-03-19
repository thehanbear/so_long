/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:55:07 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/19 15:06:21 by hlee-sun         ###   ########.fr       */
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
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_byte = read(fd, line, BUFFER_SIZE);
	if (read_byte == -1)
		read_error_free(line);
	line[read_byte] = '\0';
	while (read_byte == BUFFER_SIZE)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_byte = read(fd, temp, BUFFER_SIZE);
		if (read_byte == -1)
			read_error_free(temp);
		temp[read_byte] = '\0';
		line = ft_strjoin(line, temp);
		free(temp);
	}
	game->lines = ft_strdup(line);
	get_the_lines(game);
}

void	get_the_lines(t_game *game)
{
	int	i;

	i = 0;
	game->hei = 1;
	while (game->lines[i])
	{
		if (game->lines[i] == '\n')
			game->hei++;
		i++;
	}
	game->map = ft_split(game->lines, '\n');
	game->wid = ft_strlen(game->map[0]);
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
	copy_map(game);
	find_positions(game);
	valid_path(game, game->p_y, game->p_x);
	if (game->validity != 1)
		print_error (9);
}

void	verify_map_name(const char *file_name, const char *ending)
{
	int	i;
	int	name_len;
	int	ending_len;
	int	len;

	i = 0;
	name_len = ft_strlen(file_name);
	ending_len = ft_strlen(ending);
	if (ending_len > name_len)
		print_error (2);
	len = name_len - ending_len;
	while (file_name[len] != '\0' && ending[i] != '\0')
	{
		if (file_name[len] != ending[i])
			print_error (2);
		i++;
		len++;
	}
}

void copy_map(t_game *game)
{
	int	i;
	char **temp;

	i = 0;
	temp = malloc(game->hei * sizeof(char *));
	if (!temp)
		print_error (8);
	while(i < game->hei)
	{
		temp[i]= strdup(game->map[i]);
			i++;
	}
	game->check = temp;
}
