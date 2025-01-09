/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:45:30 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/09 16:15:31 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t *image_load(void *mlx, char *path)
{
	mlx_image_t *img;
	mlx_texture_t *texture;
	texture = mlx_load_png(path);
	img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

static void	ft_put_window(t_game *game, int c, int x, int y)
{
	mlx_t *mlx_ptr;

	mlx_ptr = get_mlx()->mlx_ptr;
	if (c == '1')
		mlx_image_to_window(mlx_ptr, game->img.wall, x, y);
	else if (c == 'P')
		mlx_image_to_window(mlx_ptr, game->img.player, x, y);
	// else if (c == 'C')
	// 	init_collect(game, x, y, &game->count);
	else if (c == 'E')
		mlx_image_to_window(mlx_ptr, game->img.exit, x, y);
}

void start_images(mlx_t *mlx_ptr)
{
	t_game *game;
	int i;
	int j;

	game = get_game();
	game->img.floor = image_load(mlx_ptr, "assets/floor.png");
	game->img.wall = image_load(mlx_ptr, "assets/wall.png");
	game->img.player = image_load(mlx_ptr, "assets/player.png");
	game->img.exit = image_load(mlx_ptr, "assets/exit.png");

	mlx_image_to_window(mlx_ptr, game->img.floor, 0, 0);
	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			ft_put_window(game, game->map.map[i][j], j * WIDTH, i * HEIGHT);
		}
	}
}
