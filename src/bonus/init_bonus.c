/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:14:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/14 17:04:54 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_map(t_game *game, char *file)
{
	char	*map;
	char	*line;

	game->file.fd = open(file, O_RDONLY);
	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(game->file.fd);
		if (!line)
			break ;
		map = ft_strjoin_with_free(map, line);
		free(line);
	}
	game->map.map = ft_split(map, '\n');
	game->flood.map = ft_split(map, '\n');
	free(map);
	close_and_clear(game->file.fd);
	ft_fill_map(&(game->map));
}

void	init_collect(t_game *game, int x, int y)
{
	int		*c;

	c = &(game->count);
	game->img.collect[*c].img = image_load(T_PATH T_COLLECT);
	game->img.collect[*c].x = x;
	game->img.collect[*c].y = y;
	mlx_image_to_window(get_mlx()->mlx_ptr, game->img.collect[*c].img, x, y);
	(*c)++;
}
