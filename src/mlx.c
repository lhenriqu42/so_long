/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:42:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/09 15:37:34 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_start_mlx(t_game *game)
{
    t_mlx *mlx;

    mlx = get_mlx();
    mlx->mlx_ptr = NULL;
    mlx_set_setting(MLX_STRETCH_IMAGE, true);
    mlx->mlx_ptr = mlx_init(WIDHT_SCREEN * game->map.x_len, HEIGHT_SCREEN
			* game->map.y_len, "so_long", true);
	if (!mlx->mlx_ptr)
		handle_error(E_MLX_ERROR);
}