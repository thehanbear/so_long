/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmac <sunmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:55:07 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/14 00:12:26 by sunmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_map_name(const char *file_name, const char *ending)
{
 	int	i;
 	int len;
 	int	j;
	
 	i = 0;
 	len = ft_strlen(file_name);
 	j = len - ft_strlen(ending);
 	while (j < len)
 	{
 		if (file_name[j] != ending[i])
 			return (1);
 		i++;
		j++;
 	}
 	return 0;
}

char	*read_map(char *map)
{
	int	fd;
	int	size;
	int	*line;

	if (verify_map_name(map, ".ber") != 0)
		print_error("Map file name error");
	fd = open(map, O_RDONLY);


	if (fd < 0 || read (fd, 0, 0) < 0)
		return (ft_free(&line));
	map = check_map(map);
	if (!map)
		return (0);
	line = (char)malloc * (sizeof(map) + 1);
	if (!line)
		return (ft_free(&line))
	
}