/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-05 09:20:08 by nayala            #+#    #+#             */
/*   Updated: 2025-11-05 09:20:08 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ff_recursive(char **map, t_point pos, int width, int height)
{
	char	cell;

	if (pos.y < 0 || pos.y >= height || pos.x < 0 || pos.x >= width)
		return ;
	cell = map[pos.y][pos.x];
	if (cell == '1' || cell == 'V')
		return ;
	map[pos.y][pos.x] = 'V';
	if (cell == 'C')
		(*pos.collectibles)++;
	if (cell == 'E')
		(*pos.exit_found) = 1;
	ff_recursive(map, (t_point){pos.x + 1,
		pos.y, pos.collectibles, pos.exit_found}, width, height);
	ff_recursive(map, (t_point){pos.x - 1,
		pos.y, pos.collectibles, pos.exit_found}, width, height);
	ff_recursive(map, (t_point){pos.x, pos.y + 1,
		pos.collectibles, pos.exit_found}, width, height);
	ff_recursive(map, (t_point){pos.x, pos.y - 1,
		pos.collectibles, pos.exit_found}, width, height);
}

char	**create_map_copy(char **map, int height)
{
	char	**copy;
	int		i;

	copy = ft_calloc(height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		if (map[i])
			copy[i] = ft_strdup(map[i]);
		else
			copy[i] = NULL;
	}
	return (copy);
}

int	flood_fill(char **map, t_game *game)
{
	char	**map_copy;
	int		collectibles_found;
	int		exit_found;
	int		i;

	map_copy = create_map_copy(map, game->map_height);
	if (!map_copy)
		return (0);
	collectibles_found = 0;
	exit_found = 0;
	if (map_copy[game->player_y][game->player_x] != '1')
	{
		ff_recursive(map_copy, (t_point){game->player_x, game->player_y,
			&collectibles_found, &exit_found},
			game->map_width, game->map_height);
	}
	i = -1;
	while (++i < game->map_height)
		free(map_copy[i]);
	free(map_copy);
	return (collectibles_found == game->collectable && exit_found);
}
