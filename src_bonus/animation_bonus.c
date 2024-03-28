/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:28:27 by akhobba           #+#    #+#             */
/*   Updated: 2024/03/28 09:16:04 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	ft_anim_enem(t_data *data)
{
	int		height;
	int		width;
	char	*s;

	height = 64;
	width = 64;
	if (data->frames < 20)
		s = "./img/Grid_f.xpm";
	else if (data->frames < 30)
		s = "./img/Grid2_f.xpm";
	else if (data->frames < 40)
		s = "./img/Grid3_f.xpm";
	else if (data->frames < 60)
		s = "./img/Grid4_f.xpm";
	else if (data->frames < 80)
	{
		s = "./img/Grid5_f.xpm";
		if (data->frames + 1 == 80)
			data->frames = 0;
	}
	data->grid = mlx_xpm_file_to_image(data->mlx, s, &width, &height);
	data->frames++;
	return (0);
}
