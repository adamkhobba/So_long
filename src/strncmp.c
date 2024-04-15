/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:51:35 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/02 10:40:32 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_strncmp(const char *s1, const char *s2, size_t n) {
  size_t i;

  i = 0;
  while (i < n && (s1[i] != '\0' || s2[i] != '\0')) {
    if (s1[i] != s2[i])
      return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    i++;
  }
  return (0);
}

void ft_plus_fts(t_map *map) {
  map = check_rec(map);
  if (map->height > 60 || map->width > 34) {
    ft_free_double_pointer(map->map, map->height);
    exit(1);
  }
  map = check_items(map);
  map = flood_fill(map, '*');
  ft_free_double_pointer(map->map, map->height);
}

void ft_putstr_mlx(t_data *data) {
  char *str;

  str = ft_itoa(data->move_count);
  ft_putstr(str);
  ft_putchar('\n');
  free(str);
}
