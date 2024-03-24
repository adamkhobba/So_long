#include "../include/so_long.h"

void ft_plus_fts(t_map *map) {
  map = check_rec(map);
  map = check_items(map);
  map = flood_fill(map, '*');
}

void ft_init(t_map *map) {
  map->error->roaderror = 0;
  map->error->wallerror = 0;
  map->error->patherror = 0;
  map->error->itemserror = 0;
  map->error->recerror = 0;
}

int ft_perror(char *path, t_map *map) {
  if (!check_map(path, map)) {
    if (map->error->patherror) {

      ft_putstr("invalid path");
    }
    if (map->error->recerror) {

      ft_putstr("the map should a rectangle frome");
    }
    if (map->error->itemserror) {

      ft_putstr("invalid items in map");
    }
    if (map->error->wallerror) {

      ft_putstr("The map should be surrounded by walls");
    }
    if (map->error->roaderror) {

      ft_putstr("Player can't access to exit or a collectif");
    }
    exit(1);
  }
  return 1;
}
