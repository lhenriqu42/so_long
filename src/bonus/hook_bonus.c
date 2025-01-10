/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:11:44 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/10 17:23:45 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_verify_path(int x, int y)
{
	if (get_game()->map.map[y / HEIGHT][x / WIDTH] == '1')
		return (0);
	return (1);
}

static void	ft_check_collect(t_img *img, int x, int y)
{
	t_game	*game;
	int		i;

	game = get_game();
	if (game->map.map[y / HEIGHT][x / WIDTH] == 'C')
	{
		game->map.map[y / HEIGHT][x / WIDTH] = '0';
		i = 0;
		while (i < game->counter.collect)
		{
			if (img->collect[i].x == x && img->collect[i].y == y)
			{
				mlx_delete_image(get_mlx()->mlx_ptr, img->collect[i].img);
				game->count--;
				break ;
			}
			i++;
		}
	}
}

static void	ft_check_exit(int x, int y)
{

	if (get_game()->map.map[y / HEIGHT][x / WIDTH] == 'K')
		handle_error(E_YOU_WERE_KILLED);
	if (get_game()->map.map[y / HEIGHT][x / WIDTH] == 'E')
	{
		if (get_game()->count == 0)
		{
			ft_printf(C_SUCCESS "Exit Found!\n" C_BREAK);
			handle_error(EXIT_SUCCESS);
		}
	}
}

static void	ft_move_player(t_img *img, int x, int y)
{
	if (ft_verify_path(x, y))
	{
		img->player->instances[0].x = x;
		img->player->instances[0].y = y;
		ft_printf("movement: %d\n", (get_game()->steps)++);
		ft_check_collect(img, x, y);
		ft_check_exit(x, y);
	}
}

void	key_hook(mlx_key_data_t key_args, void *param)
{
	t_img	*img;
	int		y;
	int		x;

	display_moves(get_game());
	img = (t_img *)param;
	y = img->player->instances[0].y;
	x = img->player->instances[0].x;
	if (key_args.key == ESC)
		mlx_close_window(get_mlx()->mlx_ptr);
	else if ((key_args.key == W || key_args.key == UP) && key_args.action != 0)
		ft_move_player(img, x, y - HEIGHT);
	else if ((key_args.key == S || key_args.key == DOWN)
		&& key_args.action != 0)
		ft_move_player(img, x, y + HEIGHT);
	else if ((key_args.key == A || key_args.key == LEFT)
		&& key_args.action != 0)
		ft_move_player(img, x - WIDTH, y);
	else if ((key_args.key == D || key_args.key == RIGHT)
		&& key_args.action != 0)
		ft_move_player(img, x + WIDTH, y);
}
