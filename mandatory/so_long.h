/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:38:42 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/10 18:26:54 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "../pictures/wall.xpm"
# define EMPTY "../pictures/empty.xpm"
# define PLAYER "../pictures/player.xpm"
# define EXIT "../pictures/exit.xpm"
# define COLLECT "../pictures/collect.xpm"
# define WIN "../pictures/winner.xpm"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "../gnl/get_next_line.h"

typedef struct s_graph
{
	void	*wall;
	void	*empty;
	void	*collect;
	void	*exit;
	void	*player;
	void	*winner;
}	t_graph;

typedef struct s_init_map
{
	int		hight;
	int		lenght;
	int		x;
	int		y;
	int		player;
	int		escape;
	int		count;
	int		step;
	char	**map;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*fn;
	t_graph	*graph;

}	t_init_map;

void	ft_read_map(t_init_map *data);
void	ft_map_hight(t_init_map *data);
void	ft_map_data(t_init_map *data, char *name);
void	ft_parse_map(t_init_map *render);
int		ft_frame(t_init_map *data);
void	ft_create_map(t_init_map *data);
int		ft_exit(t_init_map *data);
int		press_key(int keycode, t_init_map *data);

void	ft_char_set(t_init_map *data);
void	ft_check_char(t_init_map *data);
void	ft_check_format(t_init_map *data);
void	ft_check_wall(t_init_map *data);
void	ft_game_result(t_init_map *data);
void	next_lvl(t_init_map *data);

#endif