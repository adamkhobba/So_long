/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:29:26 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/02 10:44:24 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	ft_plus_fts(t_map *map)
{
	map = check_rec(map);
	map = check_items(map);
	map = flood_fill(map, '*');
	ft_free_double_pointer(map->map, map->height);
}

void	ft_init(t_map *map)
{
	map->roaderror = 0;
	map->wallerror = 0;
	map->patherror = 0;
	map->itemserror = 0;
	map->recerror = 0;
}

int	ft_perror(char *path, t_map *map)
{
	map->roaderror = 0;
	ft_init(map);
	if (!check_map(path, map))
	{
		if (map->patherror)
			ft_putstr("invalid path");
		if (map->recerror)
			ft_putstr("the map should a rectangle frome");
		if (map->itemserror)
			ft_putstr("invalid items in map");
		if (map->wallerror)
			ft_putstr("The map should be surrounded by walls");
		if (map->roaderror)
			ft_putstr("Player can't access to exit or a collectif");
		exit(1);
	}
	return (1);
}

void	ft_invalid_image(t_data *data)
{
	if (data->player == NULL)
	{
		ft_putstr("invalid image");
		exit(1);
	}
}

void	ft_invalid_image_p(t_data *data)
{
	if (data->img_ptr == NULL)
	{
		ft_putstr("invalid image");
		exit(1);
	}
}
