/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_A.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:16:06 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 14:55:32 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	a_help_collect(t_window *m_win)
{
	m_win->collect++;
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->background,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	m_win->player.x_pl--;
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->background,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	mlx_put_image_to_window(m_win->mlx, m_win->wind, m_win->m_iamges->player,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	m_win->map[m_win->player.y_pl][m_win->player.x_pl] = 'P';
	m_win->map[m_win->player.y_pl][m_win->player.x_pl + 1] = '0';
}

void	a_help_back(t_window *m_win)
{
	mlx_put_image_to_window(m_win->mlx, m_win->wind,
		m_win->m_iamges->background,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	m_win->player.x_pl--;
	mlx_put_image_to_window(m_win->mlx, m_win->wind, m_win->m_iamges->player,
		m_win->player.x_pl * 98, m_win->player.y_pl * 83);
	m_win->map[m_win->player.y_pl][m_win->player.x_pl] = 'P';
	m_win->map[m_win->player.y_pl][m_win->player.x_pl + 1] = '0';
}

void	congratulation(t_window *m_win)
{
	ft_printf("moves n* %d\n", m_win->walk++);
	ft_printf("CONGRATULATIONS & THANK YOU");
	mlx_destroy_window(m_win->mlx, m_win->wind);
	exit(1);
}

int	a_key(t_window *m_win)
{
	if (m_win->map[m_win->player.y_pl][m_win->player.x_pl - 1] == 'E' &&
		m_win->collect == m_win->max_collect)
		congratulation(m_win);
	else if (m_win->map[m_win->player.y_pl][m_win->player.x_pl - 1] != '1')
	{
		if (m_win->map[m_win->player.y_pl][m_win->player.x_pl - 1] == '0' ||
			m_win->map[m_win->player.y_pl][m_win->player.x_pl - 1] == 'P')
			a_help_back(m_win);
		else if (m_win->map[m_win->player.y_pl][m_win->player.x_pl - 1] == 'C')
			a_help_collect(m_win);
		ft_printf("moves n* %d\n", m_win->walk++);
	}
	return (0);
}
