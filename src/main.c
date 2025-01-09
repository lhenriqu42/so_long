/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:22:03 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/09 13:25:45 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_game *game;

    game = get_game();
    if (argc != 2)
        handle_error(E_INVALID_ARGS);
    ft_validate_file(argv[1]);
    ft_init_game_struct(game);
    ft_get_map(game, argv[1]);
    ft_validate_map(game);
    ft_validate_exit(&(game->flood), game->map.ppos.x, game->map.ppos.y);
    if(game->flood.collect != 0 || game->flood.exit != 0)
        handle_error(E_MAP_IMPOSSIBLE_FINISH);
}