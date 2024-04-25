/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:47:39 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 15:58:44 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	help_col(t_window *m_win, int x, int y)
{
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->background, x, y);
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->collect, x, y);
}

void	put_collect_in_map(t_window *m_win)
{
	t_put	index;

	index.i = 0;
	index.x = 0;
	index.j = 0;
	index.c = 0;
	index.y = 0;
	while (index.j < calcul_y() + 1)
	{
		index.i = 0;
		index.x = 0;
		while (m_win->map[index.j][index.i])
		{
			if (m_win->map[index.j][index.i] == 'C')
			{
				help_col(m_win, index.x, index.y);
				index.c += 1;
			}
			index.x += 98;
			index.i++;
		}
		index.y += 83;
		index.j++;
	}
	m_win->max_collect = index.c;
}

void	pla(t_window *m_win, t_put index)
{
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->background, index.x, index.y);
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->player, index.x, index.y);
	m_win->player.x_pl = index.i;
	m_win->player.y_pl = index.j;
	m_win->checkplayer.x = index.i;
	m_win->checkplayer.y = index.j;
}

void	put_player_in_map(t_window *m_win)
{
	t_put	index;

	index.i = 0;
	index.j = 0;
	index.x = 0;
	index.y = 0;
	index.check_pl = 0;
	while (index.j < calcul_y() + 1)
	{
		index.i = 0;
		index.x = 0;
		while (m_win->map[index.j][index.i])
		{
			if (m_win->map[index.j][index.i] == 'P')
			{
				pla(m_win, index);
				index.check_pl++;
			}
			index.x += 98;
			index.i++;
		}
		index.y += 83;
		index.j++;
	}
	m_win->player.number_of_pl = index.check_pl;
}
