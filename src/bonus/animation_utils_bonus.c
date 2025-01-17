/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:18:51 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/17 15:52:07 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_clean_all_directions(t_img *img, int exclude)
{
	int	i;

	i = -1;
	while (++i < img->pdown.frame_count && exclude != DOWN)
		img->pdown.frames[i]->enabled = false;
	i = -1;
	while (++i < img->pleft.frame_count && exclude != LEFT)
		img->pleft.frames[i]->enabled = false;
	i = -1;
	while (++i < img->pright.frame_count && exclude != RIGHT)
		img->pright.frames[i]->enabled = false;
	i = -1;
	while (++i < img->pup.frame_count && exclude != UP)
		img->pup.frames[i]->enabled = false;
	if (exclude != DOWN)
		img->pdown.timer = img->pdown.delay;
	if (exclude != RIGHT)
		img->pright.timer = img->pright.delay;
	if (exclude != LEFT)
		img->pleft.timer = img->pleft.delay;
	if (exclude != UP)
		img->pup.timer = img->pup.delay;
}

void	ft_handle_directions(t_img *img, int direction)
{
	ft_clean_all_directions(img, direction);
	if (direction == UP)
		update_animation(&(img->pup));
	if (direction == DOWN)
		update_animation(&(img->pdown));
	if (direction == LEFT)
		update_animation(&(img->pleft));
	if (direction == RIGHT)
		update_animation(&(img->pright));
}

void	ft_move_all_player(t_img *img, int x, int y, int i)
{
	while (++i < img->pdown.frame_count)
	{
		img->pdown.frames[i]->instances[0].x = x;
		img->pdown.frames[i]->instances[0].y = y;
	}
	i = -1;
	while (++i < img->pleft.frame_count)
	{
		img->pleft.frames[i]->instances[0].x = x;
		img->pleft.frames[i]->instances[0].y = y;
	}
	i = -1;
	while (++i < img->pright.frame_count)
	{
		img->pright.frames[i]->instances[0].x = x;
		img->pright.frames[i]->instances[0].y = y;
	}
	i = -1;
	while (++i < img->pup.frame_count)
	{
		img->pup.frames[i]->instances[0].x = x;
		img->pup.frames[i]->instances[0].y = y;
	}
}

void	init_death_animation(void)
{
	t_img	*img;
	int		i;
	int		x;
	int		y;

	i = -1;
	img = &(get_game()->img);
	y = img->pdown.frames[0]->instances[0].y;
	x = img->pdown.frames[0]->instances[0].x;
	while (++i < img->pdie.frame_count)
	{
		mlx_image_to_window(get_mlx()->mlx_ptr, img->pdie.frames[i], x, y);
		img->pdie.frames[i]->enabled = false;
	}
	ft_clean_all_directions(img, 0);
	img->finish = 1;
}
