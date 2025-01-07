/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:23:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/07 15:51:02 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[31;1m"
# define C_BREAK "\033[0m"

// ERRORS
# define E_INVALID_ARGS 1
# define E_INVALID_FILE 2
# define E_INVALID_MAP_NAME 3
# define E_INVALID_MAP_CONTENT 4

// KEY BINDS
# define W MLX_KEY_W
# define A MLX_KEY_A
# define S MLX_KEY_S
# define D MLX_KEY_D
# define UP MLX_KEY_UP
# define DOWN MLX_KEY_DOWN
# define LEFT MLX_KEY_LEFT
# define RIGHT MLX_KEY_RIGHT

// WINDOW
# define WIDHT_SCREEN 64
# define HEIGHT_SCREEN 64
# define WIDTH 64
# define HEIGHT 64



typedef struct s_draw
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	int				x;
	int				y;
}					t_draw;

typedef struct s_img
{
	t_draw			floor;
	t_draw			wall;
	t_draw			player;
	t_draw			exit;
	t_draw			collect[10000];
}					t_img;

typedef struct s_counter
{
	int				collect;
	int				walls;
	int				player;
	int				floor;
	int				exit;
	int				collect_fill;
}					t_counter;

typedef struct s_file
{
	char			*line;
	int				fd;
	char			*fill;
}					t_file;

typedef struct s_positions
{
	int				y;
	int				x;
}					t_positions;

typedef struct s_map
{
	char			**map;
	char			**fill;
	t_positions		ppos;
	size_t			x;
	size_t			y;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
	t_counter		counter;
	t_file			file;
	int				count;
	int				steps;
	t_img			img;
}					t_game;

void handle_error(short code);

#endif