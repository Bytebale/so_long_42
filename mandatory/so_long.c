/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:38:50 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/14 14:51:20 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parse_map(t_init_map *data)
{
	int	img_hight;
	int	img_width;

	data->graph = malloc(sizeof(t_graph));
	data->graph->player = mlx_xpm_file_to_image(data->mlx,
			PLAYER, &img_width, &img_hight);
	data->graph->wall = mlx_xpm_file_to_image(data->mlx,
			WALL, &img_width, &img_hight);
	data->graph->empty = mlx_xpm_file_to_image(data->mlx,
			EMPTY, &img_width, &img_hight);
	data->graph->exit = mlx_xpm_file_to_image(data->mlx,
			EXIT, &img_width, &img_hight);
	data->graph->collect = mlx_xpm_file_to_image(data->mlx,
			COLLECT, &img_width, &img_hight);
	data->graph->winner = mlx_xpm_file_to_image(data->mlx,
			WIN, &img_width, &img_hight);
}

void	ft_map_data(t_init_map *data, char *name)
{
	data->hight = 0;
	data->lenght = 0;
	data->escape = 0;
	data->count = 0;
	data->step = 0;
	data->x = 0;
	data->y = 0;
	data->player = 0;
	data->fn = name;
	ft_parse_map(data);
}

void	ft_check(t_init_map *data)
{
	ft_check_wall(data);
	ft_check_format(data);
	ft_check_char(data);
	ft_char_set(data);
}

int	ft_frame(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_create_map(data);
	if (data->count == 0 && data->player == 1 && data->escape == 1)
		ft_game_result(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_init_map	data;

	if (argc == 2)
	{
		data.mlx = mlx_init();
		ft_map_data(&data, argv[1]);
		ft_map_hight(&data);
		ft_read_map(&data);
		ft_check(&data);
		data.win = mlx_new_window(data.mlx, data.lenght * 40,
				data.hight * 40, "cucumber");
		mlx_hook(data.win, 17, 0, ft_exit, &data);
		mlx_hook(data.win, 02, 0, press_key, &data);
		mlx_loop_hook(data.mlx, ft_frame, &data);
		mlx_loop(data.mlx);
	}
}
