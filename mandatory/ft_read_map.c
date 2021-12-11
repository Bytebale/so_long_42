/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:15:11 by lshonta           #+#    #+#             */
/*   Updated: 2021/12/09 07:08:42 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_hight(t_init_map *data)
{
	char		*line;
	int			fd;

	fd = open(data->fn, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		printf("File not read\n");
		exit (EXIT_FAILURE);
	}
	while (line[data->lenght] != '\0')
		data->lenght++;
	while (line)
	{
		if (ft_strlen(line) != data->lenght)
		{
			printf("Error.Map not valide");
			exit(EXIT_FAILURE);
		}
		line = get_next_line(fd);
		data->hight++;
	}
	close(fd);
}

void	ft_read_map(t_init_map *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(data->fn, O_RDONLY);
	line = get_next_line(fd);
	data->map = (char **)malloc(sizeof(char *) * (data->hight + 1));
	i = 0;
	while (line)
	{
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}
