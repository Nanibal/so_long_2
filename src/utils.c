/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-03 09:16:08 by nayala            #+#    #+#             */
/*   Updated: 2025-06-03 09:16:08 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

void	error_exit(t_game *game, char *message)
{
	if (game)
		free_game(game);
	ft_printf("Error\n%s\n", message);
	exit(1);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

void	init_game(t_game *game, char *map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, "MLX initialize failed");
	parse_map(map, game);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
		error_exit(game, "Window creation failed");
	load_images(game);
	game->moves = 0;
}

void	flood_fill_recursive(char **map, int width, int height, t_point pos,
	int *collectibles, int *exit_found)
{
	if (pos.y < 0 || pos.y >= height || pos.x < 0 || pos.x >= width)
		return ;
	char cell = map[pos.y][pos.x];
	if (cell == '1' || cell == 'V')
		return ;
	map[pos.y][pos.x] = 'V';
	if (cell == 'C')
		(*collectibles)++;
	if (cell == 'E')
		(*exit_found) = 1;
	flood_fill_recursive(map, width, height, (t_point){pos.x + 1, pos.y},
		collectibles, exit_found);
	flood_fill_recursive(map, width, height, (t_point){pos.x - 1, pos.y},
		collectibles, exit_found);
	flood_fill_recursive(map, width, height, (t_point){pos.x, pos.y + 1},
		collectibles, exit_found);
	flood_fill_recursive(map, width, height, (t_point){pos.x, pos.y - 1},
		collectibles, exit_found);
}

int	flood_fill(char **map, int width, int height, t_point start_pos, int total_collectibles)
{
	int	collectibles_found;
	int	exit_found;
	char **map_copy;
	int i;

	map_copy = ft_calloc(height + 1, sizeof(char *));
	if (!map_copy)
		return (0);
	i = -1;
	while (++i < height)
		map_copy[i] = ft_strdup(map[i]);
	collectibles_found = 0;
	exit_found = 0;
	if (map_copy[start_pos.y][start_pos.x] != '1')
	{
		flood_fill_recursive(map_copy, width, height, start_pos, &collectibles_found, &exit_found);
	}
	i = -1;
	while (++i < height)
		free(map_copy[i]);
	free(map_copy);
	return (collectibles_found == total_collectibles && exit_found);
}
