/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-23 10:05:00 by nayala            #+#    #+#             */
/*   Updated: 2025-06-23 10:05:00 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// Counts the specific elements (P, E, C) in a map position
static void	count_elements(t_game *game, int *counts, int y, int x)
{
	if (game->map[y][x] == 'P')
	{
		counts[0]++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (game->map[y][x] == 'E')
	{
		counts[1]++;
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (game->map[y][x] == 'C')
		counts[2]++;
	else if (game->map[y][x] != '0' && game->map[y][x] != '1')
		error_exit(game, "Invalid character in map");
}

static void	check_map_contents(t_game *game)
{
	int	counts[3];
	int	x;
	int	y;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	// DEBUG: Mostrar el mapa que se está leyendo
	ft_printf("=== MAPA LEÍDO ===\n");
	y = 0;
	while (y < game->map_height)
	{
		ft_printf("Línea %d: [%s] (longitud: %d)\n", y, game->map[y], ft_strlen(game->map[y]));
		y++;
	}
	ft_printf("==================\n");
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			count_elements(game, counts, y, x);
			x++;
		}
		y++;
	}
	// DEBUG: Mostrar conteos
	ft_printf("Conteos - P: %d, E: %d, C: %d\n", counts[0], counts[1], counts[2]);
	if (counts[0] != 1 || counts[1] != 1 || counts[2] < 1)
		error_exit(game, "Map must contain 1P, 1E and at least 1C");
	game->collectable = counts[2];
}

/* static void	check_map_contents(t_game *game)
{
	int	counts[3];
	int	x;
	int	y;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			count_elements(game, counts, y, x);
			x++;
		}
		y++;
	}
	if (counts[0] != 1 || counts[1] != 1 || counts[2] < 1)
		error_exit(game, "Map must contain 1P, 1E and at least 1C");
	game->collectable = counts[2];
} */

/* static void	read_map_dimensions(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Could not open map file");
	line = get_next_line(fd);
	if (!line)
		error_exit(game, "Empty map file");
	game->map_width = ft_strlen(line) - 1;
	game->map_height = 0;
	while (line)
	{
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
} */

static void	read_map_dimensions(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Could not open map file");
	line = get_next_line(fd);
	if (!line)
		error_exit(game, "Empty map file");
	// Limpiar salto de línea para el cálculo del ancho
	if (line[ft_strlen(line) - 1] == '\n')
		game->map_width = ft_strlen(line) - 1;
	else
		game->map_width = ft_strlen(line);
	ft_printf("Map width calculated: %d\n", game->map_width);  // DEBUG
	game->map_height = 0;
	while (line)
	{
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_printf("Map height calculated: %d\n", game->map_height);  // DEBUG
}


/* void	parse_map(char *filename, t_game *game)
{
	int	fd;
	int	i;

	read_map_dimensions(game, filename);
	game->map = ft_calloc(game->map_height + 1, sizeof(char *));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < game->map_height)
	{
		game->map[i] = get_next_line(fd);
		game->map[i][game->map_width] = '\0';
		i++;
	}
	close(fd);
	check_map_contents(game);
	validate_map(game);
} */
void	parse_map(char *filename, t_game *game)
{
	int	fd;
	int	i;
	char *temp;

	read_map_dimensions(game, filename);
	game->map = ft_calloc(game->map_height + 1, sizeof(char *));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < game->map_height)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			error_exit(game, "Error reading map file");
		// Limpiar salto de línea si existe
		temp = game->map[i];
		if (temp[ft_strlen(temp) - 1] == '\n')
			temp[ft_strlen(temp) - 1] = '\0';
		// DEBUG: Mostrar línea procesada
		ft_printf("Línea %d procesada: [%s] (long: %d)\n", i, game->map[i], ft_strlen(game->map[i]));
		i++;
	}
	close(fd);
	check_map_contents(game);
	validate_map(game);
}
