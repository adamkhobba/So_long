/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:50:10 by akhobba           #+#    #+#             */
/*   Updated: 2024/03/28 07:50:19 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_getpos(t_map *map) {
  int i;
  int j;

  i = 0;
  while (i < map->height) {
    j = 0;
    while (j < map->width) {
      if (map->map[i][j] == 'P') {
        map->p_pos_y = i;
        map->p_pos_x = j;
      }
    }
  }
}

void dfs(int pos_y, int pos_x, t_map *map, char new_char) {
  if (pos_x < 0 || pos_y < 0 || pos_x >= map->width || pos_y >= map->height ||
      map->map[pos_y][pos_x] == '1' || map->map[pos_y][pos_x] == new_char)
    return;
  else {
    if (map->map[pos_y][pos_x] == 'E') {
      map->exit_counted++;
      if (map->collected != map->collectif_count)
        map->collected = 0;
    }
    if (map->map[pos_y][pos_x] == 'C')
      map->collected++;
    map->map[pos_y][pos_x] = new_char;
    dfs(pos_y + 1, pos_x, map, new_char);
    dfs(pos_y - 1, pos_x, map, new_char);
    dfs(pos_y, pos_x + 1, map, new_char);
    dfs(pos_y, pos_x - 1, map, new_char);
  }
  return;
}

t_map *flood_fill(t_map *map, char new_char) {
  char old_char;

  old_char = map->map[map->p_pos_y][map->p_pos_x];
  map->exit_counted = 0;
  map->collected = 0;
  dfs(map->p_pos_y, map->p_pos_x, map, new_char);
  if (!(map->exit_counted) || (map->collected != map->collectif_count)) {
    map->roaderror = 1;
    map->valid = 0;
  }
  return (map);
}
