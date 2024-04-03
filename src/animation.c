/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:53:13 by akhobba           #+#    #+#             */
/*   Updated: 2024/03/28 07:57:33 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_anim_enem(t_data *data) {
  int height;
  int width;
  char *s;

  height = 64;
  width = 64;
  s = NULL;
  if (data->frames < 20)
    s = "./textures/Grid_f.xpm";
  else if (data->frames < 30)
    s = "./textures/Grid2_f.xpm";
  else if (data->frames < 40)
    s = "./textures/Grid3_f.xpm";
  else if (data->frames < 60)
    s = "./textures/Grid4_f.xpm";
  else if (data->frames < 80) {
    if (data->frames + 1 == 80)
      data->frames = 0;
  }
  data->grid = mlx_xpm_file_to_image(data->mlx, s, &width, &height);
  data->frames++;
  return (0);
}
