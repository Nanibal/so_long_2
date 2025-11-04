/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-23 10:04:33 by nayala            #+#    #+#             */
/*   Updated: 2025-06-23 10:04:33 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectable == 0)
		{
			ft_printf("You won in %d moves!\n", game->moves + 1);
			close_game(game);
		}
		return ;
	}
	if (game->map[new_y][new_x] == 'C')
		game->collectable--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}
