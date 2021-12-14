/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:22:59 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/14 00:44:25 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_r(t_init_map *data, int *j, int *i)
{
	if (data->map[*j][(*i) + 1] == 'P')
	{
		data->player = 0;
		return ;
	}
	data->map[*j][*i] = '0';
	data->map[*j][(*i) + 1] = 'X';
	++(*i);
}

void	ft_move_l(t_init_map *data, int *j, int *i)
{
	if (data->map[*j][(*i) - 1] == 'P')
	{
		data->player = 0;
		return ;
	}
	data->map[*j][*i] = '0';
	data->map[*j][(*i) - 1] = 'X';
	--(*i);
}

void	ft_check_way(t_init_map *data, char c)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'X' && data->map[y][x + 1] != '1' &&
				data->map[y][x + 1] != 'E' && data->map[y][x + 1] != 'C' &&
				data->map[y][x + 1] != 'X' && c == 'r')
				ft_move_r(data, &y, &x);
			else if (data->map[y][x] == 'X' && data->map[y][x - 1] != '1' &&
				data->map[y][x - 1] != 'E' && data->map[y][x - 1] != 'C' &&
				data->map[y][x - 1] != 'X' && c == 'l')
				ft_move_l(data, &y, &x);
			x++;
		}
		y++;
	}
}

void	ft_move_enemy(t_init_map *data)
{
	static int	times;

	if (times == 10)
	{
		ft_check_way(data, 'r');
		data->enemy = 1;
	}
	if (times == 20)
	{
		ft_check_way(data, 'l');
		data->enemy = 2;
	}
	times++;
	if (times > 80)
		times = 0;
}
