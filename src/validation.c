/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:06:45 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/08 17:13:11 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_validate_file(char *file)
{
	int fd;
	char *line;

	line = "\0";
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		handle_error(E_INVALID_MAP_NAME);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_error(E_INVALID_FILE);
	line = get_next_line(fd);
	if (line == NULL || line[0] == '\0' || line[0] == '\n' || line[0] == '\r')
	{
		close(fd);
		free(line);
		handle_error(E_INVALID_MAP_CONTENT);
	}
	close(fd);
	free(line);
}

void get_map_lenght(t_map *map)
{
	map->y_len = ft_strlen(map->map[0]);
	map->x_len = 0;
	while (map->map[map->x_len])
		map->x_len++;
}

static void ft_check_wall(t_map *map)
{
	int x;
	int y;

	x = 0;
	get_map_lenght(map);
		// CORRIGIR OS X E Y E PENSAR EM COMO NOMEAR MELHOR DESENHANDO
		// CORRIGIR OS X E Y E PENSAR EM COMO NOMEAR MELHOR DESENHANDO
		// CORRIGIR OS X E Y E PENSAR EM COMO NOMEAR MELHOR DESENHANDO
	while (map->map[x])
	{
		if (map->y_len != ft_strlen(map->map[x]))
			handle_error(E_INVALID_MAP_SIZE);
		y = -1;
		while (neo->map.map[y][++x])
		{
			if (neo->map.map[0][x] != '1')
				handle_error(E_INVALID_MAP_WALLS);
			else if (neo->map.map[y][0] != '1')
				handle_error(E_INVALID_MAP_WALLS);
			else if (neo->map.map[y][neo->map.x - 1] != '1')
				handle_error(E_INVALID_MAP_WALLS);
			else if (neo->map.map[neo->map.y - 1][x] != '1')
				handle_error(E_INVALID_MAP_WALLS);
		}
		y++;
	}
	if (neo->map.x * 64 > 1920 || neo->map.y * 64 > 1080)
		handle_error(E_INVALID_MAP_SIZE);
}

void ft_validate_map(t_game *game)
{
	ft_check_wall(&(game->map));
	if (game->counter.collect == 0)
		handle_error(E_INVALID_MAP_COLLECT);
	if (game->counter.exit != 1)
		handle_error(E_INVALID_MAP_EXIT);
	if (game->counter.player != 1)
		handle_error(E_INVALID_MAP_PLAYER);
}