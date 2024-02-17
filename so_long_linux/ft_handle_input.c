/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:07:08 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/25 19:07:09 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moves_count(t_game *game)
{
	game->moves++;
	ft_putstr_fd("Movements: ", STDOUT_FILENO);
	ft_putnbr_fd(game->moves, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

int	ft_handle_input(int keysym, t_game *game)
{
	printf("k:%d\n", keysym);
	if (keysym == W_KEY)
		ft_move(game, game->map.player.x - 1, game->map.player.y, 3);
	if (keysym == A_KEY)
		ft_move(game, game->map.player.x, game->map.player.y - 1, 2);
	if (keysym == D_KEY)
		ft_move(game, game->map.player.x, game->map.player.y + 1, 1);
	if (keysym == S_KEY)
		ft_move(game, game->map.player.x + 1, game->map.player.y, 4);
	if (keysym == ESC_KEY || keysym == Q_KEY)
		ft_closed(game);
	return (0);
}

void	ft_check_exitwin(t_game *game, int nx, int ny)
{
	if (game->map.coins == 0)
		ft_winner(game);
	game->map.exit.x = nx;
	game->map.exit.y = ny;
}

void	ft_move(t_game *game, int nx, int ny, int player_pos)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	game->pj_pos = player_pos;
	if (game->map.matrix[nx][ny] != '1')
	{
		ft_moves_count(game);
		if (game->map.matrix[nx][ny] == 'E')
			ft_check_exitwin(game, nx, ny);
		if (last_x == game->map.exit.x && last_y == game->map.exit.y)
			game->map.matrix[last_x][last_y] = 'E';
		else
			game->map.matrix[last_x][last_y] = '0';
		if (game->map.matrix[nx][ny] == 'C')
			game->map.coins--;
		game->map.player.x = nx;
		game->map.player.y = ny;
		game->map.matrix[nx][ny] = 'P';
		ft_print_map (game);
	}
}
