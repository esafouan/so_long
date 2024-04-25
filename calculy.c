/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:16:28 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 18:16:53 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calcul_y(void)
{
	int		y;
	int		fd;
	char	*line;

	y = -1;
	fd = open("map.ber", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (!line)
			break ;
		y++;
	}
	return (y);
}
