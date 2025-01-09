/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:06:45 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/09 12:40:00 by lhenriqu         ###   ########.fr       */
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
		close_and_clear(fd);
		free(line);
		handle_error(E_INVALID_MAP_CONTENT);
	}
	close_and_clear(fd);
	free(line);
}

void get_map_lenght(t_map *map)
{
	map->x_len = ft_strlen(map->map[0]);
	map->y_len = 0;
	while (map->map[map->y_len])
		map->y_len++;
}

static void ft_check_wall(t_map *map)
{
	int x;
	int y;

	get_map_lenght(map);
	y = -1;
	while (map->map[++y])
	{
		if (map->x_len != ft_strlen(map->map[y]))
			handle_error(E_INVALID_MAP_SIZE);
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[0][x] != '1')
				handle_error(E_INVALID_MAP_WALLS);
			else if (map->map[y][0] != '1')
				handle_error(E_INVALID_MAP_WALLS);
			else if (map->map[y][map->x_len - 1] != '1')
				handle_error(E_INVALID_MAP_WALLS);
			else if (map->map[map->y_len - 1][x] != '1')
				handle_error(E_INVALID_MAP_WALLS);
		}
	}
	if (map->x_len * WIDTH > 1920 || map->y_len * HEIGHT > 1080)
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