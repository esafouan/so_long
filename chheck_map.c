/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chheck_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:19:59 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 11:44:43 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_nameof_map(char *map)
{
	size_t	i;

	i = gnl_strlen(map);
	if (map[i - 1] != 'r' || map[i - 2] != 'e'
		|| map[i - 3] != 'b' || map[i - 4] != '.')
		print_err("Make sure that the name of file is .ber");
}

void	check_x_walls(t_window *m_win)
{
	int	i;
	int	col;

	col = calcul_y();
	i = 0;
	while (m_win->map[0][i])
	{
		if (m_win->map[0][i] != '1')
			print_err("first line is not wall");
		i++;
	}
	i = 0;
	while (m_win->map[col][i])
	{
		if (m_win->map[col][i] != '1')
			print_err("last line is not wall");
		i++;
	}
}

void	check_y_walls(t_window *m_win)
{
	int	i;
	int	col;

	col = calcul_y() - 1;
	i = 0;
	while (i < col)
	{
		if (m_win->map[i][0] != '1')
			print_err("first colone is not wall");
		i++;
	}
	i = 0;
	while (i < col)
	{
		if (m_win->map[i][calcul_x() - 1] != '1')
			print_err("last colone is not wall");
		i++;
	}
}

int	check_rec(t_window *m_win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (calcul_x() == (calcul_y() + 1))
		print_err("map is not recto");
	while (y < calcul_y() + 1)
	{
		x = 0;
		while (m_win->map[y][x])
			x++;
		if (x != calcul_x())
			print_err("map is not recto");
		y++;
	}
	return (0);
}

void	check_pec(t_window *m_win)
{
	if (m_win->player.number_of_pl != 1)
		print_err("player must be 1");
	else if (m_win->num_of_exit != 1)
		print_err("exit must be 1");
	else if (m_win->max_collect < 1)
		print_err("collect must be 1 at least");
}
