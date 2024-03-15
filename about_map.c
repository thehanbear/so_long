/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:50:00 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/15 13:50:15 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_map_name(const char *file_name, const char *ending)
{
	int	i;
	int	name_len;
	int	ending_len;
	int	len;

	i = 0;
	name_len = ft_strlen(file_name);
	ending_len = ft_strlen(ending);
	if (ending_len > name_len)
		return (1);
	len = name_len - ending_len;
	while (file_name[len] != '\0' && ending[i] != '\0')
	{
		if (file_name[len] != ending[i])
			return (1);
		i++;
		len++;
	}
	return (0);
}

void	*read_map(char *map, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	line = get_next_line (fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->lines = ft_strdup(line);
	free(line);
	while (line != 0)
	{
		game->height++;
		line = get_next_line (fd);
		if (line != 0)
		{
			game->lines = ft_strjoin(game->lines, line);
		}
	}
	close(fd);
	printf("%s\n", game->lines);
	return (NULL);
}