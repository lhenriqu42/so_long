/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:22:03 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/08 16:38:46 by lhenriqu         ###   ########.fr       */
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

}