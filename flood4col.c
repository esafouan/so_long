/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood4col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:45:17 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 11:55:21 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	instruction(t_checkplayer position, t_window *plaayer, int i, int j)
{
	plaayer->checkplayer.x = position.x + i;
	plaayer->checkplayer.y = position.y + j;
}

void	help(char **map, t_window *plaayer)
{
	t_checkplayer	position;

	position.x = plaayer->checkplayer.x;
	position.y = plaayer->checkplayer.y;
	map[position.y][position.x] = 'W';
	if (position.y > 0 && ((map[position.y - 1][position.x] == '0')
		|| (map[position.y - 1][position.x] == 'C')))
	{
		instruction(position, plaayer, 0, -1);
		check_path_with_flood_fill(map, plaayer);
	}
	if (position.y < calcul_y() && ((map[position.y + 1][position.x] == '0')
		|| (map[position.y + 1][position.x] == 'C')))
	{
		instruction(position, plaayer, 0, 1);
		check_path_with_flood_fill(map, plaayer);
	}
}

void	check_path_with_flood_fill(char **map, t_window *plaayer)
{
	t_checkplayer	position;

	position.x = plaayer->checkplayer.x;
	position.y = plaayer->checkplayer.y;
	help(map, plaayer);
	if (position.x > 0 && ((map[position.y][position.x - 1] == '0')
		|| (map[position.y][position.x - 1] == 'C')))
	{
		instruction(position, plaayer, -1, 0);
		check_path_with_flood_fill(map, plaayer);
	}
	if (position.x < (calcul_x() - 1) && (map[position.y][position.x + 1] == '0'
		|| map[position.y][position.x + 1] == 'C'))
	{
		instruction(position, plaayer, 1, 0);
		check_path_with_flood_fill(map, plaayer);
	}
}

int	after_checkk_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < calcul_y() + 1)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C' || map[j][i] == 'E')
			{
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
