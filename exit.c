/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:08:39 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/25 18:08:41 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
	{
		free (matrix[i]);
		matrix[i] = NULL;
	}
	free (matrix);
	matrix = NULL;
}

int	ft_error_message(char *message, t_game *game)
{
	if (game->alloc == 1)
		ft_free_matrix (game->map.matrix);
	free (game);
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd (message, 1);
	exit (EXIT_FAILURE);
	return (0);
}

void	ft_winner(t_game *game)
{
	ft_free_sprites(game);
	ft_free_matrix(game->map.matrix);
	mlx_destroy_window(game->mlx_server, game->mlx_window);
	ft_putstr_fd("You win!\n", 1);
	exit(EXIT_SUCCESS);
}

int	ft_closed(t_game *game)
{
	ft_free_sprites(game);
	ft_free_matrix(game->map.matrix);
	mlx_destroy_window(game->mlx_server, game->mlx_window);
	ft_putstr_fd("You have closed the game.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
/*
int	ft_free_all(t_game *game)
{
	ft_free_sprites(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx_server, game->mlx_window);
	free(game->mlx_server);
	free(game);
	return (0);
}
*/

void	ft_free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx_server, game->s_wall.xpm_ptr);
	mlx_destroy_image(game->mlx_server, game->s_closed_exit.xpm_ptr);
	mlx_destroy_image(game->mlx_server, game->s_open_exit.xpm_ptr);
	mlx_destroy_image(game->mlx_server, game->s_pj_up.xpm_ptr);
	mlx_destroy_image(game->mlx_server, game->s_pj_right.xpm_ptr);
	mlx_destroy_image(game->mlx_server, game->s_pj_left.xpm_ptr);
	mlx_destroy_image(game->mlx_server, game->s_pj_down.xpm_ptr);
	mlx_destroy_image(game->mlx_server, game->s_floor.xpm_ptr);
	mlx_destroy_image(game->mlx_server, game->s_coin.xpm_ptr);
}
