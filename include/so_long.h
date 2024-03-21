
#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx/mlx.h"
#include "../utils/get_next_line.h"
// #include <mlx.h>
// #include <X11/keysym.h>
#define PIXEL 64

typedef struct s_map {
  char **map;
  char **visited;
  int i;
  int width;
  int height;
  int exit_count;
  int player_count;
  int collectif_count;
  int valid;
  int p_pos_x;
  int p_pos_y;
  int collected;
  int exit_counted;
  int points;
} t_map;

typedef struct s_data {
  void *mlx;
  void *win;
  int width;
  int height;
  void *textures[5];
  void *player;
  void *exit;
  void *floor;
  void *wall;
  void *ennemie;
  void *coin;
  int collected;
  int moves;
  int img_h;
  int img_w;
  t_map *map;
} t_data;

// Checking of map
t_map *check_rec(t_map *map);
t_map *check_items(t_map *map);
t_map *check_only_items(t_map *map);
int check_path(const char *path);
t_map *flood_fill(t_map *map, char new_char);
int check_map(const char *path, t_map *map);
int check_wall(char **s, int line);
char **fill_line(int fd, int line);
// Drawing of map
int draw_map(t_data *data);
int draw_map2(t_data *data);
int draw_barriers(t_data *data);
int draw_exit(t_data *data);
int draw_barriers(t_data *data);
int draw_floor(t_data *);
int draw_collectible(t_data *data);
// Game play
int put_player(t_data *data);
int move_to_right(int keysym, t_data *data);
//
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_close(t_data *data);
int ft_charchr(char *str, int c);
void ft_free_double_pointer(char **map, int line);
int ft_so_long(t_data *data);
#endif
