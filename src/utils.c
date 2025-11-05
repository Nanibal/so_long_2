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
	ft_bzero(game, sizeof(t_game));
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
