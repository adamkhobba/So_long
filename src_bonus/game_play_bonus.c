/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:30:07 by akhobba           #+#    #+#             */
/*   Updated: 2024/03/28 08:30:08 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	up(t_data *data)
{
	if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] != '1'
		&& data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] != 'E')
		data->move_count++;
	if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] == '0')
		data->map->p_pos_y = data->map->p_pos_y - 1;
	else if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] == 'P')
	{
		data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] = '0';
		data->map->p_pos_y = data->map->p_pos_y - 1;
	}
	else if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] == 'C')
	{
		data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] = '0';
		data->map->p_pos_y = data->map->p_pos_y - 1;
		data->map->collected++;
	}
	else
		ft_chose(data, 1);
	data->view = 1;
	img_ptr(data);
	draw_map(data);
	return (1);
}

int	down(t_data *data)
{
	if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] != '1'
		&& data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] != 'E')
		data->move_count++;
	if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] == '0')
		data->map->p_pos_y = data->map->p_pos_y + 1;
	else if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] == 'P')
	{
		data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] = '0';
		data->map->p_pos_y = data->map->p_pos_y + 1;
	}
	else if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] == 'C')
	{
		data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] = '0';
		data->map->p_pos_y = data->map->p_pos_y + 1;
		data->map->collected++;
	}
	else
		ft_chose(data, 2);
	data->view = 2;
	img_ptr(data);
	draw_map(data);
	return (1);
}

int	left(t_data *data)
{
	if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] != '1'
		&& data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] != 'E')
		data->move_count++;
	if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] == '0')
		data->map->p_pos_x = data->map->p_pos_x - 1;
	else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] == 'p')
	{
		data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] = '0';
		data->map->p_pos_x = data->map->p_pos_x - 1;
	}
	else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] == 'C')
	{
		data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] = '0';
		data->map->p_pos_x = data->map->p_pos_x - 1;
		data->map->collected++;
	}
	else
		ft_chose(data, 4);
	data->view = 4;
	img_ptr(data);
	draw_map(data);
	return (1);
}

int	right(t_data *data)
{
	if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] != '1'
		&& data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] != 'E')
		data->move_count++;
	if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] == '0')
		data->map->p_pos_x = data->map->p_pos_x + 1;
	else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] == 'p')
	{
		data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] = '0';
	}
	else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] == 'C')
	{
		data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] = '0';
		data->map->p_pos_x = data->map->p_pos_x + 1;
		data->map->collected++;
	}
	else
		ft_chose(data, 3);
	data->view = 3;
	img_ptr(data);
	draw_map(data);
	return (1);
}

int	move(int keysym, t_data *data)
{
	if (keysym == 13)
	{
		mlx_clear_window(data->mlx, data->win);
		up(data);
		ft_putstr_mlx(data);
	}
	else if (keysym == 1)
	{
		mlx_clear_window(data->mlx, data->win);
		down(data);
		ft_putstr_mlx(data);
	}
	else if (keysym == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		left(data);
		ft_putstr_mlx(data);
	}
	else if (keysym == 2)
	{
		mlx_clear_window(data->mlx, data->win);
		right(data);
		ft_putstr_mlx(data);
	}
	return (1);
}
