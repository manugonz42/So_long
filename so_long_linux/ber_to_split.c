/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_to_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:10:24 by manugonz          #+#    #+#             */
/*   Updated: 2023/09/25 16:10:32 by manugonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	save_pos(t_game *game, int x, int y, char c)
{
	if (c == 'p')
	{
		game->map.player.x = x;
		game->map.player.y = y;
	}
	else
	{
		game->map.exit.x = x;
		game->map.exit.x = x;
	}
}

void	check_nlines(t_game *game, char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s) - 1;
	i = 0;
	if (s[i] == '\n')
		ft_error_message("First lane is empty.\n", game);
	if (s[len] == '\n')
		ft_error_message("Last lane is empty.\n", game);
	while (i++ < len)
		if (s[i] == '\n' && s[i + 1] == '\n')
			ft_error_message("The map have an empty lane.\n", game);
}

void	check_map_params(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (++x < game->map.rows - 1)
	{
		y = 0;
		while (++y < game->map.columns - 1)
		{
			if (game->map.matrix[x][y] == 'C')
				game->map.coins++;
			else if (game->map.matrix[x][y] == 'P')
			{
				game->map.players++;
				save_pos(game, x, y, 'p');
			}
			else if (game->map.matrix[x][y] == 'E')
			{
				game->map.exits++;
				save_pos(game, x, y, 'e');
			}
			else if (!ft_strchr("CPE01", game->map.matrix[x][y]))
				ft_error_message("Invalid char in the map\n", game);
		}
	}
}

void	ber_to_split(char *v, t_game *game)
{
	int		fd;
	char	*temp_str;
	char	*temp_rd;

	fd = open(v, O_RDONLY);
	if (fd == -1)
		ft_error_message("Failed to open the archive .ber, check it", game);
	temp_str = ft_strdup("");
	game->map.rows = 0;
	while (1)
	{
		temp_rd = get_next_line(fd);
		if (temp_rd == NULL)
			break ;
		temp_str = ft_strlcpycat(temp_str, temp_rd);
		game->map.rows++;
		free(temp_rd);
	}	
	close (fd);
	check_nlines(game, temp_str);
	game->map.matrix = ft_split(temp_str, '\n');
	game->alloc = 1;
	free (temp_str);
}

char	*ft_strlcpycat(char *s1, char *s2)
{
	char	*res;

	res = calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (res);
}
