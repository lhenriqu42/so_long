/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:23:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/09 16:57:40 by lhenriqu         ###   ########.fr       */
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
# define E_MLX_ERROR 1
# define E_INVALID_ARGS 2
# define E_INVALID_FILE 3
# define E_INVALID_MAP_NAME 4
# define E_INVALID_MAP_SIZE 5
# define E_INVALID_MAP_CHAR 6
# define E_INVALID_MAP_EXIT 7
# define E_INVALID_MAP_WALLS 8
# define E_INVALID_MAP_PLAYER 9
# define E_INVALID_MAP_CONTENT 10
# define E_INVALID_MAP_COLLECT 11
# define E_MAP_IMPOSSIBLE_FINISH 12

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


typedef struct s_img
{
	mlx_image_t			*floor;
	mlx_image_t			*wall;
	mlx_image_t			*player;
	mlx_image_t			*exit;
	mlx_image_t			*collect[10000];
}					t_img;

typedef struct s_counter
{
	int				collect;
	int				walls;
	int				player;
	int				floor;
}					t_counter;

typedef struct s_file
{
	int				fd;
}					t_file;

typedef struct s_positions
{
	int				y;
	int				x;
}					t_positions;

typedef struct s_map
{
	char			**map;
	t_positions		ppos;
	size_t x_len;
	size_t y_len;
}					t_map;

typedef struct s_flood
{
	int			collect;
	int			exit;
	char		**map;
}				t_flood;

typedef struct s_mlx
{
	mlx_t		*mlx_ptr;
}				t_mlx;

typedef struct s_game
{
	t_map			map;
	t_counter		counter;
	t_file			file;
	int				count;
	int				steps;
	t_flood			flood;
	t_img			img;
}					t_game;

void	ft_validate_exit(t_flood *flood, int x, int y);
void	ft_init_game_struct(t_game *matrice);
void	ft_get_map(t_game *game, char* file);
void	ft_validate_map(t_game *game);
void	ft_validate_file(char *file);
void	get_map_lenght(t_map *map);
void	handle_error(short code);
void	ft_fill_map(t_map *map);
t_game	*get_game();
void start_images(mlx_t *mlx_ptr);
t_mlx	*get_mlx();
void ft_start_mlx(t_game *game);

#endif