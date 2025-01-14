/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:23:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/14 16:22:53 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// TEXTURE PATHS
# define T_PATH "assets/"
# define T_BONUS "bonus/"

// ANIMATED TEXTURE PATH
# define AT_DIE "die/"
# define AT_ENEMY "enemy/"
# define AT_PDOWN "pdown/"
# define AT_PLEFT "pleft/"
# define AT_PRIGHT "pright/"
# define AT_PUP "pup/"

// ANIMATED TEXTURE COUNT
# define ATC_DIE 6
# define ATC_ENEMY 10
# define ATC_PDOWN 6
# define ATC_PLEFT 9
# define ATC_PRIGHT 9
# define ATC_PUP 6

// TEXTURE NAMES
# define T_COLLECT "ore.png"
# define T_FLOOR "floor.png"
# define T_EXIT "exit.png"
# define T_WALL "wall.png"

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[31;1m"
# define C_BREAK "\033[0m"

// SIMPLE ERRORS
# define E_INVALID_ARGS 1
# define E_INVALID_FILE 2
# define E_INVALID_MAP_NAME 3
# define E_INVALID_MAP_CONTENT 4

// MAP ERRORS
# define E_MLX_ERROR 5
# define E_YOU_WERE_KILLED 13
# define E_INVALID_MAP_SIZE 6
# define E_INVALID_MAP_CHAR 7
# define E_INVALID_MAP_EXIT 8
# define E_INVALID_MAP_WALLS 9
# define E_INVALID_MAP_PLAYER 10
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
# define ESC MLX_KEY_ESCAPE

// TEXTURE BLOCK SIZE
# define WIDTH 80
# define HEIGHT 80

typedef struct s_coin
{
	mlx_image_t		*img;
	int				x;
	int				y;
}					t_coin;

typedef struct s_animation
{
	mlx_image_t	*frames[20];
	mlx_image_t	*current_frame;
	int			frame_count;
	int			current_index;
	int			delay;
	int			timer;
}				t_animation;

typedef struct s_img
{
	mlx_image_t			*floor;
	mlx_image_t			*wall;
	mlx_image_t			*exit;
	t_animation			pright;
	t_animation			pleft;
	t_animation			pdown;
	t_animation			pup;
	t_animation			pdie;
	t_animation			enemy;
	t_coin				collect[10000];
}						t_img;

typedef struct s_counter
{
	int				collect;
	int				player;
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
	size_t			x_len;
	size_t			y_len;
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

// VALIDATION FUNCTIONS
void		ft_validate_exit(t_flood *flood, int x, int y);
void		ft_validate_map(t_game *game);
void		ft_validate_file(char *file);

// START FUNCTIONS
void		init_collect(t_game *game, int x, int y);
void		ft_init_game_struct(t_game *matrice);
void		ft_get_map(t_game *game, char *file);
void		ft_init_animations(t_img *img);
void		start_images(mlx_t *mlx_ptr);
void		ft_start_mlx(t_game *game);
void		ft_fill_map(t_map *map);

// UTILS FUNCTIONS
void		key_hook(mlx_key_data_t key_args, void *param);
mlx_image_t	*image_load(char *path);
void		get_map_lenght(t_map *map);
void		handle_error(short code);
void		display_moves(t_game *game);
t_game		*get_game(void);
t_mlx		*get_mlx(void);
void		update_animation(t_animation *anim);


#endif