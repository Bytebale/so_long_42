/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:28:55 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/14 19:59:49 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_steps(t_init_map *data)
{
	char	*mov;
	char	*moves;

	moves = ft_itoa(data->step);
	mov = ft_str_join("Step: ", moves);
	mlx_string_put(data->mlx, data->win, 2 * 40 + 1,
		0, 0x00FF0000, mov);
	free(mov);
	free(moves);
}

void	ft_lose(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->graph->loser,
		data->lenght * 40 / 2.4, data->hight * 40 / 4);
}

void	ft_win(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->graph->winner,
		data->lenght * 40 / 2.4, data->hight * 40 / 4);
}
