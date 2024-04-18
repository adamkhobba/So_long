/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:53:13 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/18 15:57:59 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
