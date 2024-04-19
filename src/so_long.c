/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:49:12 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/19 09:29:25 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <unistd.h>

int	ft_so_long(t_data *data)
{
	data->height = data->map->height * PIXEL;
	data->width = data->map->width * PIXEL;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width - 64, data->height,
			"The Old Castle");
	data->map->collected = 0;
	data->view = 2;
	data->move_count = 0;
	img_ptr(data);
	draw_map(data);
	put_player(data);
	mlx_hook(data->win, 17, (1L << 19), &ft_close, data);
	mlx_hook(data->win, 3, (1L << 0), &close_window, data);
	mlx_loop(data->mlx);
	return (1);
}

int	main(int arc, char **arv)
{
	t_data	data;
	t_map	mp;
	int		fd;

	if (arc != 2)
		return (0);
	data.map = &mp;
	ft_perror(arv[1], data.map);
	fd = open(arv[1], O_RDWR);
	if (fd < 0)
		return (0);
	data.map->map = fill_line(fd, data.map->height);
	ft_so_long(&data);
	return (0);
}
