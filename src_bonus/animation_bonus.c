/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:28:27 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/18 16:15:55 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	ft_check_size(t_map *map)
{
	map = check_rec(map);
	if (map->height > 34 || map->width > 60)
	{
		ft_free_double_pointer(map->map, map->height);
		ft_putstr("invalid size");
		ft_putstr("did you seen any game has");
		ft_putstr("a over size than your  monitor *^!@#");
		exit(1);
	}
}

int	ft_anim_enem(t_data *data)
{
	int		height;
	int		width;
	char	*s;

	height = 64;
	width = 64;
	s = NULL;
	if (data->frames < 20 * 2)
		s = "./textures/Grid_f.xpm";
	else if (data->frames < 30 * 2)
		s = "./textures/Grid2_f.xpm";
	else if (data->frames < 40 * 2)
		s = "./textures/Grid3_f.xpm";
	else if (data->frames < 60 * 2)
		s = "./textures/Grid4_f.xpm";
	else if (data->frames < 80 * 2)
	{
		s = "./textures/Grid5_f.xpm";
		if (data->frames + 1 == 80 * 2)
			data->frames = 0;
	}
	data->grid = mlx_xpm_file_to_image(data->mlx, s, &width, &height);
	ft_invalid_image_grid(data);
	data->frames++;
	return (0);
}

int	ft_movement_enemy(t_data *data)
{
	int	i;

	i = 0;
	data->y = 0;
	while (data->y < data->map->height)
	{
		data->x = -1;
		while (data->x++ < data->map->width)
		{
			if (data->map->map[data->y][data->x] == 'G')
			{
				data->map->map[data->y][data->x] = '0';
				if (data->map->map[data->y][data->x + 1] == '0' && i <= 1)
					data->map->map[data->y][data->x + 1] = 'G';
				else if (data->map->map[data->y][data->x - 1] == '0' && i > 1)
					data->map->map[data->y][data->x - 1] = 'G';
				data->x++;
			}
			if (i > 2)
				i = 0;
			i++;
		}
		data->y++;
	}
	return (1);
}
