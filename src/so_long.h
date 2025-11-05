/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-03 08:03:13 by nayala            #+#    #+#             */
/*   Updated: 2025-06-03 08:03:13 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectable;
	int		moves;
	int		exit_x;
	int		exit_y;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
}			t_game;
//for thw flood fill
typedef struct s_point
{
	int	x;
	int	y;
	int	*collectibles;
	int	*exit_found;
}		t_point;

// Map parsing
void	parse_map(char *filename, t_game *game);
void	validate_map(t_game *game);
// Game initialize
void	init_game(t_game *game, char *map);
void	load_images(t_game *game);
// Game rendering
void	render_map(t_game *game);
// Game logic
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
// Utils
void	free_game(t_game *game);
void	error_exit(t_game *game, char *message);
int		close_game(t_game *game);
int		flood_fill(char **map, t_game *game);
void	init_game(t_game *game, char *map);
char	**create_map_copy(char **map, int height);
#endif