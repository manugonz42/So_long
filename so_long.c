/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:10:17 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/25 19:10:19 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	leaks()
{
	system("leaks so_long -list -fullContent");
}
*/
//	atexit(leaks);
int	main(int argc, char const *argv[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_arguments(argc, (char *)argv[1], game);
	ber_to_split((char *)argv[1], game);
	check_rows_size(game);
	wall_check(game);
	ft_init_vars(game);
	check_map_params(game);
	check_parameters(game);
	check_dfs(game);
	ft_mlx_init(game);
	ft_sprites_init(game);
	ft_print_map(game);
	mlx_key_hook(game->mlx_window, ft_handle_input, game);
	mlx_hook(game->mlx_window, 17, 0, ft_closed, game);
	mlx_loop(game->mlx_server);
	return (0);
}
