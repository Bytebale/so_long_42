/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/14 18:34:55 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_w(t_init_map *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
			data->count--;
		}
		else if (data->map[data->y - 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		else if (data->map[data->y - 1][data->x] == 'E'
			&& data->count == 0)
			data->escape = 1;
		else if (data->map[data->y - 1][data->x] == 'X')
			data->player = 0;
		data->y--;
		data->step++;
	}
}

void	move_s(t_init_map *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		if (data->map[data->y + 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
			data->count--;
		}
		else if (data->map[data->y + 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
		}
		else if (data->map[data->y + 1][data->x] == 'E'
			&& data->count == 0)
			data->escape = 1;
		else if (data->map[data->y + 1][data->x] == 'X')
			data->player = 0;
		data->y++;
		data->step++;
	}
}

void	move_a(t_init_map *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		if (data->map[data->y][data->x - 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
			data->count--;
		}
		else if (data->map[data->y][data->x - 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		else if (data->map[data->y][data->x - 1] == 'E'
			&& data->count == 0)
			data->escape = 1;
		else if (data->map[data->y][data->x - 1] == 'X')
			data->player = 0;
		data->x--;
		data->step++;
	}
}

void	move_d(t_init_map *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		if (data->map[data->y][data->x + 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
			data->count--;
		}
		else if (data->map[data->y][data->x + 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		else if (data->map[data->y][data->x + 1] == 'E'
			&& data->count == 0)
			data->escape = 1;
		else if (data->map[data->y][data->x + 1] == 'X')
			data->player = 0;
		data->x++;
		data->step++;
	}
}

int	press_key(int keycode, t_init_map *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		move_w(data);
	else if (keycode == A)
		move_a(data);
	else if (keycode == S)
		move_s(data);
	else if (keycode == D)
		move_d(data);
	return (0);
}
