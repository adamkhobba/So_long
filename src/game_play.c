/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:50:46 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/02 11:05:06 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int up(t_data *data) {
  if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] != '1' &&
      data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] != 'E')
    data->move_count++;
  if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] == '0')
    data->map->p_pos_y = data->map->p_pos_y - 1;
  else if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] == 'P')
    data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] = '0';
  else if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] == 'C') {
    data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] = '0';
    data->map->p_pos_y = data->map->p_pos_y - 1;
    data->map->collected++;
  } else if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] ==
                 'E' &&
             data->map->collected == data->map->collectif_count) {
    data->move_count++;
    ft_putstr_mlx(data);
    ft_close_win(data);
  }
  data->view = 1;
  img_ptr(data);
  draw_map(data);
  return (1);
}

int down(t_data *data) {
  if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] != '1' &&
      data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] != 'E')
    data->move_count++;
  if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] == '0')
    data->map->p_pos_y = data->map->p_pos_y + 1;
  else if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] == 'P')
    data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] = '0';
  else if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] == 'C') {
    data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] = '0';
    data->map->p_pos_y = data->map->p_pos_y + 1;
    data->map->collected++;
  } else if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] ==
                 'E' &&
             data->map->collected == data->map->collectif_count) {
    data->move_count++;
    ft_putstr_mlx(data);
    ft_close_win(data);
  }
  data->view = 2;
  img_ptr(data);
  draw_map(data);
  return (1);
}

int left(t_data *data) {
  if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] != '1' &&
      data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] != 'E')
    data->move_count++;
  if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] == '0')
    data->map->p_pos_x = data->map->p_pos_x - 1;
  else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] == 'P')
    data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] = '0';
  else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] == 'C') {
    data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] = '0';
    data->map->p_pos_x = data->map->p_pos_x - 1;
    data->map->collected++;
  } else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] ==
                 'E' &&
             data->map->collected == data->map->collectif_count) {
    data->move_count++;
    ft_putstr_mlx(data);
    ft_close_win(data);
  }
  data->view = 4;
  img_ptr(data);
  draw_map(data);
  return (1);
}

int right(t_data *data) {
  if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] != '1' &&
      data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] != 'E')
    data->move_count++;
  if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] == '0')
    data->map->p_pos_x = data->map->p_pos_x + 1;
  else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] == 'P')
    data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] = '0';
  else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] == 'C') {
    data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] = '0';
    data->map->p_pos_x = data->map->p_pos_x + 1;
    data->map->collected++;
  } else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] ==
                 'E' &&
             data->map->collected == data->map->collectif_count) {
    data->move_count++;
    ft_putstr_mlx(data);
    ft_close_win(data);
  }
  data->view = 3;
  img_ptr(data);
  draw_map(data);
  return (1);
}

int move(int keysym, t_data *data) {
  if (keysym == 13) {
    mlx_clear_window(data->mlx, data->win);
    up(data);
    ft_putstr_mlx(data);
  } else if (keysym == 1) {
    mlx_clear_window(data->mlx, data->win);
    down(data);
    ft_putstr_mlx(data);
  } else if (keysym == 0) {
    mlx_clear_window(data->mlx, data->win);
    left(data);
    ft_putstr_mlx(data);
  } else if (keysym == 2) {
    mlx_clear_window(data->mlx, data->win);
    right(data);
    ft_putstr_mlx(data);
  }
  return (1);
}
