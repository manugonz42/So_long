/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:57:54 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/26 13:57:56 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <mlx.h>
//# include "mlx/mlx_int.h"
# include "gnl/get_next_line.h"

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**matrix;
	int		columns;
	int		rows;
	int		coins;
	int		exits;
	int		players;
	t_pos	player;
	t_pos	exit;
}				t_map;

typedef struct s_game
{
	t_map	map;
	int		alloc;
	int		moves;
	void	*mlx_server;
	void	*mlx_window;
	int		pj_pos;
	int		c_count;
	t_image	s_wall;
	t_image	s_floor;
	t_image	s_coin;
	t_image	s_open_exit;
	t_image	s_closed_exit;
	t_image	s_pj_right;
	t_image	s_pj_left;
	t_image	s_pj_up;
	t_image	s_pj_down;
}				t_game;

# define IMG_BITS			32
# define WALL				'1'
# define SPACE 				'0'
# define COIN 	 			'C'
# define PLAYER				'P'
# define EXIT 			 	'E'

# define W_KEY				13
# define A_KEY				0
# define S_KEY				1
# define D_KEY				2
# define ESC_KEY			53
# define Q_KEY				12

# define S_WALL				"assets/sprites/wall.xpm"
# define S_FLOOR			"assets/sprites/floor.xpm"
# define S_COIN				"assets/sprites/coin.xpm"
# define S_EXIT_CLOSED		"assets/sprites/eclosed.xpm"
# define S_EXIT_OPENED		"assets/sprites/eopen.xpm"
# define S_PJ_RIGHT			"assets/sprites/pj/right.xpm"
# define S_PJ_LEFT			"assets/sprites/pj/left.xpm"
# define S_PJ_UP			"assets/sprites/pj/up.xpm"
# define S_PJ_DOWN			"assets/sprites/pj/down.xpm"

void	check_arguments(int c, char *v, t_game *game);
int		ft_error_message(char *message, t_game *game);
void	ber_to_split(char *v, t_game *game);
char	*ft_strlcpycat(char *s1, char *s2);
void	start_value(t_game *game);
void	check_rows_size(t_game *game);
void	check_nlines(t_game *game, char *s);
void	wall_check(t_game *game);
void	check_map_params(t_game *game);
void	check_parameters(t_game *game);
void	check_dfs(t_game *game);
int		is_valid_path(char **map, t_game *game);
int		dfs(char **map, int x, int y, t_game *game);
int		is_valid_position(char **map, int x, int y, t_game *game);
void	ft_mlx_towin(t_game *game, int x, int y, t_image image);
void	ft_mlx_init(t_game *game);
void	ft_sprites_init(t_game *game);
t_image	ft_new_sprite(void *mlx, char *dir, t_game *game);
void	ft_what_to_print(t_game *game, int x, int y);
int		ft_print_map(t_game *game);
char	**ft_dup_matrix(char **matrix, int colums, int rows);
void	ft_init_vars(t_game *game);
int		ft_free_all(t_game *game);
void	ft_free_sprites(t_game *game);
void	ft_free_matrix(char **matrix);
void	ft_print_pj(t_game *game, int x, int y);
void	ft_move(t_game *game, int nx, int ny, int player_pos);
int		ft_handle_input(int keysym, t_game *game);
void	ft_winner(t_game *game);
int		ft_closed(t_game *game);
void	save_pos(t_game *game, int x, int y, char c);

#endif