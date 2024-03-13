/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmac <sunmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:27:55 by hlee-sun          #+#    #+#             */
/*   Updated: 2024/03/13 23:41:46 by sunmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - ft_strlen(s2);
	if ( j < 0 )
		return (1);
	while (s1[j] == s2[i] && s1[j] != '\0')
	{
		if (s1[j] != s2[i])
			return (s1[j] - s2[i]);
		i++;
		j++;
	}
	if (s1[j] == s2[i])
		return (0);
	else
		return (s1[j] - s2[i]);
}