/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:30:37 by esafouan          #+#    #+#             */
/*   Updated: 2022/12/11 16:46:30 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct player
{
	int	x_pl;
	int	y_pl;
	int	number_of_pl;
}	t_player;

typedef struct checkplayer
{
	int	x;
	int	y;
}	t_checkplayer;

typedef struct image
{
	void	*background;
	void	*player;
	void	*wall;
	void	*collect;
	void	*exit;
}	t_image;

typedef struct checkmap{
	char	**map_tomp;
}	t_checkmap;

typedef struct window{
	void				*mlx;
	void				*wind;
	int					win_x;
	int					win_y;
	char				**map;
	struct player		player;
	struct checkplayer	checkplayer;
	struct image		*m_iamges;
	int					collect;
	int					max_collect;
	int					col;
	int					num_of_exit;
	int					walk;
}	t_window;

typedef struct put_element
{
	int	i;
	int	j;
	int	x;
	int	c;
	int	check_pl;
	int	y;
	int	check_exit;
}	t_put;

void	print_err(char *s);
int		calcul_x(void);
int		calcul_y(void);
int		xpm_to_image(t_window *m_win);
int		moves(int keycode, t_window *m_win);
void	put_collect_in_map(t_window *m_win);
void	put_player_in_map(t_window *m_win);
void	put_wall_in_map(t_window *m_win);
void	put_back_in_map(t_window *m_win);
void	put_exit_in_map(t_window *m_win);
int		a_key(t_window *m_win);
int		d_key(t_window *m_win);
int		w_key(t_window *m_win);
int		s_key(t_window *m_win);
char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	check_pec(t_window *m_win);
void	check_x_walls(t_window *m_win);
void	check_y_walls(t_window *m_win);
void	check_path_with_flood_fill(char **map, t_window *plaayer);
void	check_path_with_flood_fill_for_exit(char **map, t_window *plaayer);
int		after_checkk_path(char **map);
char	**read_file(char *arg, t_checkmap *check);
void	check_for_newline(char *str);
void	check_nameof_map(char *map);
void	print_err(char *s);
int		check_rec(t_window *m_win);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n);
int		ft_hexadicimal_ouper(unsigned int n);
int		ft_hexadicimal_lower(unsigned int n);
int		adress(unsigned long n);
int		ft_printf(const char *s, ...);
void	congratulation(t_window *m_win);
int		exit_game(t_window *m_win);
#endif
