/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-03 08:02:50 by nayala            #+#    #+#             */
/*   Updated: 2025-06-03 08:02:50 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit(NULL, "Usage: ./so_long map_file.ber");
	ft_bzero (&game, sizeof(t_game));
	init_game(&game, argv[1]);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
