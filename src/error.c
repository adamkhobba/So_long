/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:49:49 by akhobba           #+#    #+#             */
/*   Updated: 2024/03/28 13:00:03 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	system("leaks so_long");
		exit(1);
	}
	return (1);
}
