/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:31:41 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/17 15:51:54 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_strjoin_png(char *dir_path, int index)
{
	char	*temp2;
	char	*temp;
	char	*num;

	temp = ft_strjoin(T_PATH T_BONUS, dir_path);
	num = ft_itoa(index);
	temp2 = ft_strjoin_with_free(temp, num);
	free(num);
	return (ft_strjoin_with_free(temp2, ".png"));
}

static void	load_anim(t_animation *anim, char *path, int frame_qnt, int delay)
{
	char	*temp;
	int		i;

	i = 0;
	anim->delay = delay;
	anim->frame_count = frame_qnt;
	while (i < frame_qnt)
	{
		temp = ft_strjoin_png(path, i);
		anim->frames[i] = image_load(temp);
		free(temp);
		i++;
	}
}

void	ft_init_animations(t_img *img)
{
	load_anim(&(img->pup), AT_PUP, ATC_PUP, 5);
	load_anim(&(img->pdown), AT_PDOWN, ATC_PDOWN, 5);
	load_anim(&(img->pleft), AT_PLEFT, ATC_PLEFT, 5);
	load_anim(&(img->pright), AT_PRIGHT, ATC_PRIGHT, 5);
	load_anim(&(img->pdie), AT_DIE, ATC_DIE, 10);
	load_anim(&(img->enemy), AT_ENEMY, ATC_ENEMY, 10);
}

void	update_animation(t_animation *anim)
{
	int	new_index;

	anim->timer++;
	if (anim->timer >= anim->delay)
	{
		anim->timer = 0;
		new_index = (anim->current_index + 1) % anim->frame_count;
		anim->frames[anim->current_index]->enabled = false;
		anim->frames[new_index]->enabled = true;
		anim->current_index = new_index;
	}
}
