#include "so_long.h"

void	read_error_free(char *line)
{
	free(line);
	print_error(1);
}

void	print_error(int type)
{
	if (type == 1)
		write(1, "Error\nMap read error.\n", 23);
	if (type == 2)
		write(1, "Error\ninvalid map name.\n", 25);
	if (type == 3)
		write(1, "Error\nMap must be rectangular.\n", 32);
	if (type == 4)
		write(1, "Error\nEmpty line.\n", 19);
	if (type == 5)
		write(1, "Error\nMap must be surrounded by walls.\n", 40);
	if (type == 6)
		write(1, "Error\nMap must contain 1 E, 1 P, and at least 1 C.\n", 52);
	if (type == 7)
		write(1, "Error\nMap contains invalid characters.\n", 40);
	if (type == 8)
		write(1, "Error\nMemory allocation error.\n", 21);
	if (type == 9)
		write(1, "Error\ninvalid map path.\n", 25);
	exit (1);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->hei)
	{
		if (game->map && game->map[i])
			free(game->map[i]);
		if (game->check && game->check[i])
			free(game->check[i]);
		i++;
	}
	if (game->map)
		free(game->map);
	if (game->check)
		free(game->check);
	if (game->lines)
		free(game->lines);
}

char	*strjoin_free(char *s1, char *s2)
{
	char	*strjoin;

	strjoin = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (strjoin);
}

