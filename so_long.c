/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:23:53 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 18:28:04 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_window index, t_checkmap check)
{
	check_path_with_flood_fill(check.map_tomp, &index);
	check_path_with_flood_fill_for_exit(check.map_tomp, &index);
	if (after_checkk_path(check.map_tomp))
		print_err("invalid path !!!!");
}

void	put_element(t_window index)
{
	put_wall_in_map(&index);
	put_back_in_map(&index);
}

void	walls(t_window index)
{
	check_x_walls(&index);
	check_y_walls(&index);
}

void	creat_window(t_window	*index)
{
	index->wind = mlx_new_window(index->mlx,
			index->win_x, index->win_y, "so_long");
}

int	main(int argc, char **argv)
{
	t_checkmap	check;
	t_window	index;

	if (argc == 2)
	{
		index.mlx = mlx_init();
		index.win_x = 98 * calcul_x();
		index.win_y = 83 * (calcul_y() + 1);
		index.map = read_file(argv[1], &check);
		check_rec(&index);
		creat_window(&index);
		xpm_to_image(&index);
		walls(index);
		put_element(index);
		put_exit_in_map(&index);
		put_collect_in_map(&index);
		put_player_in_map(&index);
		check_pec(&index);
		mlx_hook(index.wind, 2, 0, moves, &index);
		mlx_hook(index.wind, 17, 0, exit_game, &index);
		check_path(index, check);
		mlx_loop(index.mlx);
	}
	else
		print_err("ghir 2 arg baraka");
}
