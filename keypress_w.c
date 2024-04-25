/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_W.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:20:40 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 15:26:27 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	w_help_collect(t_window *m_win)
{
	m_win->collect++;
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->background,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	m_win->player.y_pl--;
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->background,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	mlx_put_image_to_window(m_win->mlx, m_win->wind, m_win->m_iamges->player,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	m_win->map[m_win->player.y_pl][m_win->player.x_pl] = 'P';
	m_win->map[m_win->player.y_pl + 1][m_win->player.x_pl] = '0';
}

void	w_help_back(t_window *m_win)
{
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->background,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	m_win->player.y_pl--;
	mlx_put_image_to_window(m_win->mlx, m_win->wind, m_win->m_iamges->player,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	m_win->map[m_win->player.y_pl][m_win->player.x_pl] = 'P';
	m_win->map[m_win->player.y_pl + 1][m_win->player.x_pl] = '0';
}

int	w_key(t_window *m_win)
{
	if (m_win->map[m_win->player.y_pl - 1][m_win->player.x_pl] == 'E' &&
			m_win->collect == m_win->max_collect)
		congratulation(m_win);
	else if (m_win->map[m_win->player.y_pl - 1][m_win->player.x_pl] != '1')
	{
		if (m_win->map[m_win->player.y_pl - 1][m_win->player.x_pl] == '0' ||
			m_win->map[m_win->player.y_pl - 1][m_win->player.x_pl] == 'P')
			w_help_back(m_win);
		else if (m_win->map[m_win->player.y_pl - 1][m_win->player.x_pl] == 'C')
			w_help_collect(m_win);
		ft_printf("moves n* %d\n", m_win->walk++);
	}
	return (0);
}

int	moves(int keycode, t_window *m_win)
{
	if (keycode == 0)
		a_key(m_win);
	else if (keycode == 13)
		w_key(m_win);
	else if (keycode == 2)
		d_key(m_win);
	else if (keycode == 1)
		s_key(m_win);
	else if (keycode == 53)
	{
		mlx_destroy_window(m_win->mlx, m_win->wind);
		exit(1);
	}
	return (0);
}
