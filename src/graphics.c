/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-23 10:04:45 by nayala            #+#    #+#             */
/*   Updated: 2025-06-23 10:04:45 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	load_images(t_game *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&img_size, &img_size);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&img_size, &img_size);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&img_size, &img_size);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &img_size, &img_size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&img_size, &img_size);
	if (!game->wall || !game->floor || !game->player
		|| !game->collect || !game->exit)
		error_exit(game, "Failed to load textures");
}

void	render_map(t_game *game)
{
	int	cord[2];

	mlx_clear_window(game->mlx, game->win);
	cord[0] = -1;
	while (++cord[0] < game->map_height)
	{
		cord[1] = -1;
		while (++cord[1] < game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor,
				cord[1] * TILE_SIZE, cord[0] * TILE_SIZE);
			if (game->map[cord[0]][cord[1]] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->floor,
					cord[1] * TILE_SIZE, cord[0] * TILE_SIZE);
			else if (game->map[cord[0]][cord[1]] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect,
					cord[1] * TILE_SIZE, cord[0] * TILE_SIZE);
			else if (game->map[cord[0]][cord[1]] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit,
					cord[1] * TILE_SIZE, cord[0] * TILE_SIZE);
			else if (game->map[cord[0]][cord[1]] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->player,
					cord[1] * TILE_SIZE, cord[0] * TILE_SIZE);
		}
	}
}

/* static void	render_aux(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x
				* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img,
					x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

void	render_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_aux(game);

} */