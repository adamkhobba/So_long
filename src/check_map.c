/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:35:43 by adam              #+#    #+#             */
/*   Updated: 2024/03/24 08:13:37 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int line_len(int fd) {
  int counter;
  char *s;

  counter = 0;
  s = get_next_line(fd);
  if (!s)
    return (0);
  while (s) {
    free(s);
    s = get_next_line(fd);
    counter++;
  }
  return counter;
}

void ft_free_double_pointer(char **map, int line) {
  int i;
  i = 0;
  while (i < line) {
    free(map[i]);
    i++;
  }
  free(map);
}

int ft_charchr(char *str, int c) {
  int i;
  int len;
  i = 0;
  len = 0;
  while (str[i]) {
    if (str[i] == c)
      len++;
    i++;
  }
  return len;
}

char **fill_line(int fd, int line) {
  int i;
  char **map;

  map = (char **)malloc(sizeof(char *) * (line + 1));
  if (!map)
    return 0;
  map[0] = get_next_line(fd);
  if (!map[0])
    return (NULL);
  i = 1;
  while (i < line + 1) {
    map[i] = get_next_line(fd);
    i++;
  }
  return (map);
}

int check_map(const char *path, t_map *map) {
  int fd;

  if (!check_path(path)) {
    map->error->patherror = 1;
    return 0;
  }
  fd = open(path, O_RDWR);
  if (fd < 0)
    return 0;
  map->height = line_len(fd);
  close(fd);
  fd = open(path, O_RDWR);
  map->valid = 1;
  map->map = fill_line(fd, map->height);
  printf("a\n");
  if (map->map == NULL)
    return (0);
  if (check_wall(map->map, map->height) == 0) {
    map->error->wallerror = 1;
    return (0);
  }
  ft_plus_fts(map);
  ft_free_double_pointer(map->map, map->height);
  close(fd);
  if (!map->valid)
    return (0);
  return (1);
} // <= 25 line
