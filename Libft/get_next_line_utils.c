/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmac <sunmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:19:56 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/15 11:31:15 by sunmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_string(char *str)
{
	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		*str = 0;
	}
	return (str);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = 0;
	return (0);
}