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
	void	*mlx;		// Minilibx conexion
	void	*win;		// Game window
	char	**map;		// Map matrix
	int		map_width;
	int		map_height;
	int		player_x;	//Player cordinates
	int		player_y;	//Player cordinates
	int		collectable;
	int		moves;		// Moves count
	int		exit_x;		// Exit cordinates
	int		exit_y;		// Exit cordinates
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
int		flood_fill(char **map, int width, int height, t_point pos);
void	init_game(t_game *game, char *map);
#endif