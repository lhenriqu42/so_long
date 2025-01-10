/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:47:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/10 13:30:40 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_verify_char(int c, int x, int y)
{
	t_game	*game;

	game = get_game();
	if (c == 'C')
	{
		game->counter.collect++;
		game->flood.collect++;
	}
	else if (c == 'E')
		game->flood.exit++;
	else if (c == 'P')
	{
		game->counter.player++;
		game->map.ppos.y = y;
		game->map.ppos.x = x;
	}
}

void	ft_fill_map(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (!ft_strchr("CEP10", map->map[y][x]))
				handle_error(E_INVALID_MAP_CHAR);
			ft_verify_char(map->map[y][x], x, y);
		}
	}
}
