/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:56:28 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/26 13:56:30 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//x = columns (row lengh)
void	ft_mlx_init(t_game *game)
{
	game->mlx_server = mlx_init();
	if (!game->mlx_server)
	{
		free(game->mlx_server);
		ft_error_message("Mlx server start failed.\n", game);
	}
	game->mlx_window = mlx_new_window(game->mlx_server, \
			game->map.columns * IMG_BITS, game->map.rows * IMG_BITS, "so_long");
	if (!game->mlx_window)
	{
		free (game->mlx_server);
		ft_error_message("Mlx window creation failed.\n", game);
	}
}

void	ft_sprites_init(t_game *game)
{
	game->s_wall = ft_new_sprite(game->mlx_server, S_WALL, game);
	game->s_coin = ft_new_sprite(game->mlx_server, S_COIN, game);
	game->s_floor = ft_new_sprite(game->mlx_server, S_FLOOR, game);
	game->s_open_exit = ft_new_sprite(game->mlx_server, S_EXIT_OPENED, game);
	game->s_closed_exit = ft_new_sprite(game->mlx_server, S_EXIT_CLOSED, game);
	game->s_pj_right = ft_new_sprite(game->mlx_server, S_PJ_RIGHT, game);
	game->s_pj_left = ft_new_sprite(game->mlx_server, S_PJ_LEFT, game);
	game->s_pj_up = ft_new_sprite(game->mlx_server, S_PJ_UP, game);
	game->s_pj_down = ft_new_sprite(game->mlx_server, S_PJ_DOWN, game);
}

t_image	ft_new_sprite(void *mlx, char *dir, t_game *game)
{
	t_image	image;

	image.xpm_ptr = mlx_xpm_file_to_image(mlx, dir, &image.x, &image.y);
	if (!image.xpm_ptr)
		ft_error_message("Xpm image doesn't exit.\n", game);
	return (image);
}
