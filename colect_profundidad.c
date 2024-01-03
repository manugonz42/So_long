/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colect_profundidad.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:12:42 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/25 16:12:44 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_position(char **map, int x, int y, t_game *game)
{
	if (map[x][y] == 'C')
		game->c_count++;
	return (x >= 1 && x < game->map.rows - 1 && y >= 1 && \
		y < game->map.columns - 1 && map[x][y] != '1' && map[x][y] != 'V');
}

int	dfs(char **map, int x, int y, t_game *game)
{
	static int	e_finded = 0;

	if (map[x][y] == 'E')
		e_finded = 1;
	if (e_finded == 1 && game->c_count == game->map.coins)
		return (1);
	map[x][y] = 'V';
	if (is_valid_position(map, x - 1, y, game) && dfs (map, x - 1, y, game))
		return (1);
	if (is_valid_position(map, x + 1, y, game) && dfs (map, x + 1, y, game))
		return (1);
	if (is_valid_position(map, x, y - 1, game) && dfs (map, x, y - 1, game))
		return (1);
	if (is_valid_position(map, x, y + 1, game) && dfs (map, x, y + 1, game))
		return (1);
	return (0);
}

int	is_valid_path(char **map, t_game *game)
{
	return (dfs(map, game->map.player.x, game->map.player.y, game));
}

char	**ft_dup_matrix(char **matrix, int colums, int rows)
{
	char	**dm;
	int		x;
	int		y;

	x = -1;
	dm = malloc (sizeof(char *) * (rows + 1));
	while (++x < rows)
		dm[x] = malloc (sizeof(char) * (colums + 1));
	x = -1;
	while (++x < rows)
	{
		y = -1;
		{
			while (++y < colums)
				dm[x][y] = matrix[x][y];
			dm[x][y] = 0;
		}
	}
	dm[x] = NULL;
	return (dm);
}

void	check_dfs(t_game *game)
{
	char	**dm;

	dm = ft_dup_matrix(game->map.matrix, game->map.columns, game->map.rows);
	if (!is_valid_path(dm, game))
	{
		ft_free_matrix(dm);
		ft_error_message("There is no valid path to the exit.\n", game);
	}
	ft_free_matrix(dm);
}
