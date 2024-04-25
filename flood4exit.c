/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood4exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:09:41 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 13:15:22 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	instruction2(t_checkplayer position, t_window *plaayer, int i, int j)
{
	plaayer->checkplayer.x = position.x + i;
	plaayer->checkplayer.y = position.y + j;
}

void	help2(char **map, t_window *plaayer)
{
	t_checkplayer	position;

	position.x = plaayer->checkplayer.x;
	position.y = plaayer->checkplayer.y;
	map[position.y][position.x] = 'D';
	if (position.y > 0 && ((map[position.y - 1][position.x] == 'W')
		|| (map[position.y - 1][position.x] == 'E')))
	{
		instruction2(position, plaayer, 0, -1);
		check_path_with_flood_fill_for_exit(map, plaayer);
	}
	if (position.y < calcul_y() && ((map[position.y + 1][position.x] == 'W')
		|| (map[position.y + 1][position.x] == 'E')))
	{
		instruction2(position, plaayer, 0, 1);
		check_path_with_flood_fill_for_exit(map, plaayer);
	}
}

void	check_path_with_flood_fill_for_exit(char **map, t_window *plaayer)
{
	t_checkplayer	position;

	position.x = plaayer->checkplayer.x;
	position.y = plaayer->checkplayer.y;
	help2(map, plaayer);
	if (position.x > 0 && ((map[position.y][position.x - 1] == 'W')
		|| (map[position.y][position.x - 1] == 'E')))
	{
		instruction2(position, plaayer, -1, 0);
		check_path_with_flood_fill_for_exit(map, plaayer);
	}
	if (position.x < (calcul_x() - 1) && (map[position.y][position.x + 1] == 'W'
		|| map[position.y][position.x + 1] == 'E'))
	{
		instruction2(position, plaayer, 1, 0);
		check_path_with_flood_fill_for_exit(map, plaayer);
	}
}
