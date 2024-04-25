/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_10E.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:27:16 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 18:18:28 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_wall_in_map(t_window *m_win)
{
	t_put	index;

	index.i = 0;
	index.x = 0;
	index.j = 0;
	index.y = 0;
	while (index.j < calcul_y() + 1)
	{
		index.i = 0;
		index.x = 0;
		while (m_win->map[index.j][index.i])
		{
			if (m_win->map[index.j][index.i] == '1')
				mlx_put_image_to_window(m_win->mlx,
					m_win->wind, m_win->m_iamges->wall, index.x, index.y);
			index.x += 98;
			index.i++;
		}
		index.y += 83;
		index.j++;
	}
}

void	put_back_in_map(t_window *m_win)
{
	t_put	index;

	index.i = 0;
	index.x = 0;
	index.j = 0;
	index.y = 0;
	while (index.j < calcul_y() + 1)
	{
		index.i = 0;
		index.x = 0;
		while (m_win->map[index.j][index.i])
		{
			if (m_win->map[index.j][index.i] == '0')
				mlx_put_image_to_window(m_win->mlx,
					m_win->wind, m_win->m_iamges->background, index.x, index.y);
			index.x += 98;
			index.i++;
		}
		index.y += 83;
		index.j++;
	}
}

void	help_exit(t_window *m_win, t_put index)
{
	mlx_put_image_to_window(m_win->mlx,
		m_win->wind, m_win->m_iamges->exit, index.x, index.y);
}

void	put_exit_in_map(t_window *m_win)
{
	t_put	index;

	index.i = 0;
	index.x = 0;
	index.j = 0;
	index.check_exit = 0;
	index.y = 0;
	while (index.j < calcul_y() + 1)
	{
		index.i = 0;
		index.x = 0;
		while (m_win->map[index.j][index.i])
		{
			if (m_win->map[index.j][index.i] == 'E')
			{
				help_exit(m_win, index);
				index.check_exit++;
			}
			index.x += 98;
			index.i++;
		}
		index.y += 83;
		index.j++;
	}
	m_win->num_of_exit = index.check_exit;
}

int	exit_game(t_window *m_win)
{
	mlx_destroy_window(m_win->mlx, m_win->wind);
	ft_printf("You close the game");
	exit(0);
}
