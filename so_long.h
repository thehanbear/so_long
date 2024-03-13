/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmac <sunmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:36:18 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/14 00:00:37 by sunmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./Libft/libft.h" 

# ifndef BUFFER_SIZE
# define BUFFER_SIZE

// typedef	struct	s_map
// {
// 	int	fd;
// 	int	size;
// 	int	len;
// }	t_map;

char	ft_strcpy(char *dest, char *src);
void    print_error(char *str);

#endif