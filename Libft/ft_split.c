/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlee-sun <hlee-sun@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:26:13 by hlee-sun          #+#    #+#             */
/*   Updated: 2023/11/23 12:58:37 by hlee-sun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sub_split(const char *s, char c, size_t start)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*sub;

	i = start;
	len = 0;
	if (!s)
		return (0);
	while (s[i + len] != c && s[i + len])
		len++;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	j = 0;
	while (j < len)
	{
		sub[j] = s[i + j];
		j++;
	}
	sub[len] = '\0';
	return (sub);
}

static char	**ft_real_split(char const *s, char c, char **split, size_t count)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (count > i)
	{
		while (s[start] == c && s[start])
			start++;
		split[i] = ft_sub_split(s, c, start);
		if (!split[i])
		{
			while (i--)
				free(split[i]);
			free(split);
			return (0);
		}
		i++;
		while (s[start] != c && s[start])
			start++;
	}
	split[count] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**split;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	split = ft_real_split(s, c, split, count);
	return (split);
}
