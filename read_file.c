/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:01:12 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 18:27:03 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_newline(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		print_err("just new line in map !!!");
	if (str[0] == '\0')
		print_err("empty map");
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			print_err("new line in map !!!");
		i++;
	}
}

char	**read_file(char *arg, t_checkmap *check)
{
	int		fd;
	char	*line;
	char	**split;
	char	**tompo;
	char	*buffer;

	check_nameof_map(arg);
	buffer = gnl_calloc(1, 1);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		print_err("file not exist");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		buffer = gnl_strjoin(buffer, line);
		free(line);
	}
	check_for_newline(buffer);
	tompo = ft_split(buffer, '\n');
	check->map_tomp = tompo;
	split = ft_split(buffer, '\n');
	free(buffer);
	return (split);
}

int	xpm_to_image(t_window *m_win)
{
	int		high;
	int		weidgh;
	t_image	*index;

	high = 0;
	weidgh = 0;
	index = malloc(sizeof(t_image));
	index->background = mlx_xpm_file_to_image(m_win->mlx,
			"./texture/se7ra.xpm", &high, &weidgh);
	index->collect = mlx_xpm_file_to_image(m_win->mlx,
			"./texture/jerry.xpm", &high, &weidgh);
	index->exit = mlx_xpm_file_to_image(m_win->mlx,
			"./texture/exitse7ra.xpm", &high, &weidgh);
	index->player = mlx_xpm_file_to_image(m_win->mlx,
			"./texture/tom.xpm", &high, &weidgh);
	index->wall = mlx_xpm_file_to_image(m_win->mlx,
			"./texture/dregu.xpm", &high, &weidgh);
	m_win->m_iamges = index;
	return (0);
}

void	print_err(char *s)
{
	ft_printf("Error\n%s", s);
	exit(0);
}
