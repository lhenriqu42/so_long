/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:25:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/08 16:12:09 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void print_error(char *str)
{
    ft_printf_fd(2, C_ERROR "%s\n" C_BREAK, str);
}

static void map_error(char *str)
{
    t_game *game;

    game = get_game();
    print_error(str);
    if (game->flood.map)
        ft_delete_game(game->flood.map);
    if (game->map.map)
        ft_delete_game(game->map.map);
    if (game->mlx_ptr)
        mlx_terminate(game->mlx_ptr);
}

void handle_error(short code)
{
    if (code == E_INVALID_MAP_SIZE)
        map_error("invalid map size");
    if (code == E_INVALID_MAP_WALLS)
        map_error("invalid map walls");
    if (code == E_INVALID_MAP_CHAR)
        map_error("invalid character!");
    if (code == E_MAP_IMPOSSIBLE_FINISH)
        map_error("map can't be finished!");
    if (code == E_INVALID_MAP_CONTENT)
        print_error("invalid map content!");
    if (code == E_INVALID_FILE)
        perror(C_ERROR "invalid file" C_BREAK);
    if (code == E_MLX_ERROR)
        map_error("mlx cannot be initialized!");
    if (code == E_INVALID_ARGS)
        print_error("expected: ./so_long <map>");
    if (code == E_INVALID_MAP_EXIT)
        map_error("map must have exactly one exit.");
    if (code == E_INVALID_MAP_NAME)
        print_error("maps must be terminated by .ber");
    if (code == E_INVALID_MAP_PLAYER)
        map_error("map must have exactly one player.");
    if (code == E_INVALID_MAP_COLLECT)
        map_error("map must contain at least one collectible.");
    exit(code);
}