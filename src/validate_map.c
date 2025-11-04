/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-23 08:14:13 by nayala            #+#    #+#             */
/*   Updated: 2025-06-23 08:14:13 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	map_is_close(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if ((y == 0 || y == game->map_height - 1 || x == 0
					|| x == game->map_width -1) && game->map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	has_valid_path(t_game *game)
{
	char	**map_cpy;
	int		i;
	int		reach;

	map_cpy = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!map_cpy)
		return (0);
	i = -1;
	while (++i < game->map_height)
		map_cpy[i] = ft_strdup(game->map[i]);
	reach = flood_fill(map_cpy, game->map_width, game->map_height,
			(t_point){game->player_x, game->player_y}, game->collectable);
	i = -1;
	while (++i < game->map_height)
		free(map_cpy[i]);
	free(map_cpy);
	return (reach);
}

void	validate_map(t_game *game)
{
	if (!map_is_close(game))
		error_exit(game, "Map is not surrounded by walls");
	if (!has_valid_path(game))
		error_exit(game, "No valid path in map");
	if (game->map_height < 3 || game->map_width < 3)
		error_exit(game, "Map is too small");
	if (game->map_height > 22 || game->map_width > 40)
		error_exit(game, "Map is too big");
}
