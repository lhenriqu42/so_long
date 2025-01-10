/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:25:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/10 15:47:39 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_e(char *str)
{
	ft_printf_fd(2, C_ERROR "%s\n" C_BREAK, str);
}

static void	print_s(char *str)
{
	ft_printf_fd(1, C_SUCCESS "%s\n" C_BREAK, str);
}

static void	map_error(char *str, void (*callback)(char *str))
{
	t_game	*game;

	game = get_game();
	callback(str);
	if (game->flood.map)
		ft_free_matrix(game->flood.map);
	if (game->map.map)
		ft_free_matrix(game->map.map);
	if (get_mlx()->mlx_ptr)
		mlx_terminate(get_mlx()->mlx_ptr);
}

static void	handle_map_error(short code)
{
	if (code == EXIT_SUCCESS)
		map_error("Finalizado!\n", &print_s);
	if (code == E_INVALID_MAP_SIZE)
		map_error("invalid map size", &print_e);
	if (code == E_INVALID_MAP_WALLS)
		map_error("invalid map walls", &print_e);
	if (code == E_INVALID_MAP_CHAR)
		map_error("invalid character!", &print_e);
	if (code == E_MAP_IMPOSSIBLE_FINISH)
		map_error("map can't be finished!", &print_e);
	if (code == E_MLX_ERROR)
		map_error("mlx cannot be initialized!", &print_e);
	if (code == E_INVALID_MAP_EXIT)
		map_error("map must have exactly one exit.", &print_e);
	if (code == E_INVALID_MAP_PLAYER)
		map_error("map must have exactly one player.", &print_e);
	if (code == E_INVALID_MAP_COLLECT)
		map_error("map must contain at least one collectible.", &print_e);
}

void	handle_error(short code)
{
	if (code >= 5 || code == EXIT_SUCCESS)
		handle_map_error(code);
	if (code == E_INVALID_MAP_CONTENT)
		print_e("invalid map content!");
	if (code == E_INVALID_FILE)
		perror(C_ERROR "invalid file" C_BREAK);
	if (code == E_INVALID_ARGS)
		print_e("expected: ./so_long <map>");
	if (code == E_INVALID_MAP_NAME)
		print_e("maps must be terminated by .ber");
	exit(code);
}
