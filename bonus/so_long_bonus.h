/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:38:42 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/14 20:02:34 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define WALL "./pictures/wall.xpm"
# define EMPTY "./pictures/empty.xpm"
# define PLAYER "./pictures/player.xpm"
# define EXIT "./pictures/exit.xpm"
# define COLLECT "./pictures/collect.xpm"
# define WIN "./pictures/winner.xpm"
# define ENEMY "./pictures/enemy.xpm"
# define ENEMY_A "./pictures/enemy1.xpm"
# define LOSER "./pictures/loser.xpm"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include <stdlib.h>
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
	void	*enemy_1;
	void	*enemy_2;
	void	*loser;
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
	int		lvl;
	int		enemy;
	char	**map;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*fn;
	t_graph	*graph;

}	t_init_map;

int		ft_frame(t_init_map *data);
int		ft_exit(t_init_map *data);
int		press_key(int keycode, t_init_map *data);
void	ft_map_data(t_init_map *data, char *name);
void	ft_parse_map(t_init_map *data);
void	ft_check(t_init_map *data);
void	ft_read_map(t_init_map *data);
void	ft_map_hight(t_init_map *data);
void	ft_create_map(t_init_map *data);
void	put_empty_img(t_init_map *data, int *j, int *i);
void	put_wall_img(t_init_map *data, int *j, int *i);
void	put_player_img(t_init_map *data, int *j, int *i);
void	ft_draw_enemy(t_init_map *data, int *j, int *i);
void	move_d(t_init_map *data);
void	move_a(t_init_map *data);
void	move_s(t_init_map *data);
void	move_w(t_init_map *data);
char	*ft_itoa(int n);
void	ft_print_steps(t_init_map *data);
void	ft_lose(t_init_map *data);
void	ft_win(t_init_map *data);
void	put_collect_img(t_init_map *data, int *j, int *i);
void	ft_move_enemy(t_init_map *data);
void	ft_check_way(t_init_map *data, char c);
void	ft_move_l(t_init_map *data, int *j, int *i);
void	ft_move_r(t_init_map *data, int *j, int *i);
void	ft_next_lvl(t_init_map *data);
void	ft_char_set(t_init_map *data);
void	ft_check_char(t_init_map *data);
void	ft_check_format(t_init_map *data);
void	ft_check_wall(t_init_map *data);
char	*ft_str_join(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	free_map(t_init_map *data);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dest, const void *src, size_t len);

#endif