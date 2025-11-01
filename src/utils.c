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

int	flood_fill(char **map, int width, int height, t_point pos)
{
	static int	collectibles = 0;
	static int	exit_found = 0;

	if (pos.y < 0 || pos.y >= height || pos.x < 0 || pos.x >= width
		|| map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'X')
		return (collectibles && exit_found);
	if (map[pos.y][pos.x] == 'C')
		collectibles++;
	if (map[pos.y][pos.x] == 'X')
		exit_found++;
	flood_fill(map, width, height, (t_point){pos.x + 1, pos.y});
	flood_fill(map, width, height, (t_point){pos.x - 1, pos.y});
	flood_fill(map, width, height, (t_point){pos.x, pos.y + 1});
	flood_fill(map, width, height, (t_point){pos.x, pos.y - 1});
	return (collectibles && exit_found);
}
