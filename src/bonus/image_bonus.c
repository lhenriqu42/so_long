/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:45:30 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/14 17:06:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*image_load(char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(get_mlx()->mlx_ptr, texture);
	mlx_delete_texture(texture);
	return (img);
}

static void put_enemy(mlx_t *mlx_ptr, int x, int y)
{
	int i;
	t_img *img;

	i = 0;
	img = &(get_game()->img);
	while(i < img->enemy.frame_count)
	{
		mlx_image_to_window(mlx_ptr, get_game()->img.enemy.frames[i], x, y);
		get_game()->img.enemy.frames[i]->enabled = false;
		i++;
	}
}

static void	ft_put_to_window(t_game *game, int c, int x, int y)
{
	mlx_t	*mlx_ptr;

	mlx_ptr = get_mlx()->mlx_ptr;
	if (c == '1')
		mlx_image_to_window(mlx_ptr, game->img.wall, x, y);
	else if (c == 'C')
		init_collect(game, x, y);
	else if (c == 'E')
		mlx_image_to_window(mlx_ptr, game->img.exit, x, y);
	else if (c == 'K')
		put_enemy(mlx_ptr, x, y);
}

void	start_images(mlx_t *mlx_ptr)
{
	t_game	*game;
	int		i;
	int		j;

	game = get_game();
	game->img.floor = image_load(T_PATH T_FLOOR);
	game->img.wall = image_load(T_PATH T_WALL);
	game->img.exit = image_load(T_PATH T_EXIT);
	mlx_image_to_window(mlx_ptr, game->img.floor, 0, 0);
	ft_init_animations(&(game->img));
	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			ft_put_to_window(game, game->map.map[i][j], j * WIDTH, i * HEIGHT);
		}
	}
}
