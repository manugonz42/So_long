/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:50:24 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/26 13:50:26 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_vars(t_game *game)
{
	game->pj_pos = 1;
	game->map.coins = 0;
	game->moves = 0;
	game->c_count = 0;
	game->map.exits = 0;
	game->map.players = 0;
}	

void	check_arguments(int c, char *v, t_game *game)
{
	int	len;

	if (c != 2)
		ft_error_message("Wrong number of parameters\n", game);
	len = ft_strlen(v);
	if (!ft_strnstr(v + len - 4, ".ber", 4))
		ft_error_message("Wrong format of archive\n", game);
}

void	check_rows_size(t_game *game)
{
	int		i;
	size_t	fr_columns;

	i = 0;
	fr_columns = ft_strlen (game->map.matrix[0]);
	while (++i < game->map.rows - 1)
		if (fr_columns != ft_strlen(game->map.matrix[i]))
			ft_error_message("Map not valid.\n", game);
	if (fr_columns - 1 != ft_strlen(game->map.matrix[i]))
		ft_error_message("Map not valid.\n", game);
	game->map.columns = ft_strlen(game->map.matrix[0]) - 1;
}

void	wall_check(t_game *game)
{
	int	i;
	int	rlen;
	int	clen;

	i = -1;
	clen = game->map.columns;
	rlen = game->map.rows;
	while (++i < clen)
		if (game->map.matrix[0][i] != '1')
			ft_error_message("Map must be surrounded by walls.\n", game);
	i = -1;
	while (++i < clen)
		if (game->map.matrix[rlen - 1][i] != '1')
			ft_error_message ("Map must be surrounded by walls.\n", game);
	i = -1;
	while (++i < rlen)
		if (game->map.matrix[i][0] != '1')
			ft_error_message("Map must be surrounded by walls.\n", game);
	i = -1;
	while (++i < rlen)
		if (game->map.matrix[i][clen - 1] != '1')
			ft_error_message("Map must be surrounded by walls.\n", game);
}

void	check_parameters(t_game *game)
{
	if (game->map.players != 1)
		ft_error_message("Just one player allowed.\n", game);
	if (game->map.coins < 1)
		ft_error_message("Map must have at least 1 collectable.\n", game);
	if (game->map.exits != 1)
		ft_error_message("Just one exit allowed.\n", game);
}
