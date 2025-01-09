/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:14:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/09 12:40:07 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init_game_struct(t_game *game)
{
    game->counter.collect = 0;
    game->counter.walls = 0;
    game->counter.player = 0;
    game->counter.floor = 0;
    game->counter.exit = 0;
    game->map.map = NULL;
    game->map.x_len = 0;
    game->map.y_len = 0;
    game->map.ppos.x = 0;
    game->map.ppos.y = 0;
    game->flood.collect = 0;
    game->flood.map = NULL;
    game->count = 0;
    game->steps = 1;
    game->mlx_ptr = NULL;
}

void ft_get_map(t_game *game, char *file)
{
    char *map;
    char *line;

    game->file.fd = open(file, O_RDONLY);
    map = ft_strdup("");
    while (1)
    {
        line = get_next_line(game->file.fd);
        if (!line)
            break;
        map = ft_strjoin_with_free(map, line);
        free(line);
    }
    game->map.map = ft_split(map, '\n');
    game->flood.map = ft_split(map, '\n');
    free(map);
    close_and_clear(game->file.fd);
    ft_fill_map(&(game->map));
}
