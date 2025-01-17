/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:45:30 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/17 15:55:29 by lhenriqu         ###   ########.fr       */
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

static void	put_enemy(mlx_t *mlx_ptr, int x, int y)
{
	int		i;
	t_img	*img;

	i = 0;
	img = &(get_game()->img);
	while (i < img->enemy.frame_count)
	{
		mlx_image_to_window(mlx_ptr, img->enemy.frames[i], x, y);
		img->enemy.frames[i]->enabled = false;
		i++;
	}
}

static void	put_player(t_img *img, int x, int y, int i)
{
	while (++i < img->pdown.frame_count)
	{
		mlx_image_to_window(get_mlx()->mlx_ptr, img->pdown.frames[i], x, y);
		img->pdown.frames[i]->enabled = false;
	}
	i = -1;
	while (++i < img->pleft.frame_count)
	{
		mlx_image_to_window(get_mlx()->mlx_ptr, img->pleft.frames[i], x, y);
		img->pleft.frames[i]->enabled = false;
	}
	i = -1;
	while (++i < img->pright.frame_count)
	{
		mlx_image_to_window(get_mlx()->mlx_ptr, img->pright.frames[i], x, y);
		img->pright.frames[i]->enabled = false;
	}
	i = -1;
	while (++i < img->pup.frame_count)
	{
		mlx_image_to_window(get_mlx()->mlx_ptr, img->pup.frames[i], x, y);
		img->pup.frames[i]->enabled = false;
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
	else if (c == 'P')
	{
		put_player(&(game->img), x, y, -1);
		game->img.pdown.frames[0]->enabled = true;
	}
}

void	start_images(mlx_t *mlx_ptr)
{
	t_game	*game;
	int		i;
	int		j;

	game = get_game();
	game->img.floor = image_load(T_PATH T_FLOOR);
	game->img.exit = image_load(T_PATH T_EXIT);
	game->img.wall = image_load(T_PATH T_BONUS T_WALL);
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
	game->img.pdown.timer = game->img.pdown.delay;
	game->img.pleft.timer = game->img.pleft.delay;
	game->img.pright.timer = game->img.pright.delay;
	game->img.pup.timer = game->img.pup.delay;
	game->img.pdie.timer = game->img.pdie.delay;
}
