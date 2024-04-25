/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:16:06 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 18:17:01 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calcul_x(void)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	x = gnl_strlen(line);
	free(line);
	return (x - 1);
}
