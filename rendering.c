/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:08:30 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/25 19:08:31 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_towin(t_game *game, int x, int y, t_image image)
{
	mlx_put_image_to_window (game->mlx_server, game->mlx_window, \
		image.xpm_ptr, y * image.y, x * image.x);
}

void	ft_what_to_print(t_game *game, int x, int y)
{
	if (game->map.matrix[x][y] == 'C')
		ft_mlx_towin(game, x, y, game->s_coin);
	if (game->map.matrix[x][y] == 'P')
		ft_print_pj(game, x, y);
	if (game->map.matrix[x][y] == 'E')
	{
		if (game->map.coins == 0)
			ft_mlx_towin(game, x, y, game->s_open_exit);
		else
			ft_mlx_towin(game, x, y, game->s_closed_exit);
	}
	if (game->map.matrix[x][y] == '0')
		ft_mlx_towin(game, x, y, game->s_floor);
	if (game->map.matrix[x][y] == '1')
		ft_mlx_towin(game, x, y, game->s_wall);
}

void	ft_print_pj(t_game *game, int x, int y)
{
	if (game->pj_pos == 1)
		ft_mlx_towin(game, x, y, game->s_pj_right);
	if (game->pj_pos == 2)
		ft_mlx_towin(game, x, y, game->s_pj_left);
	if (game->pj_pos == 3)
		ft_mlx_towin(game, x, y, game->s_pj_up);
	if (game->pj_pos == 4)
		ft_mlx_towin(game, x, y, game->s_pj_down);
}

int	ft_print_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->map.rows)
	{
		y = -1;
		while (++y < game->map.columns)
			ft_what_to_print(game, x, y);
	}
	return (0);
}
