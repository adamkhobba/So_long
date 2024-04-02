/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:49:16 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/02 10:44:50 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H

#include "../utils/get_next_line.h"
#include <mlx.h>
#define PIXEL 64

typedef struct s_map {
  char **map;
  char **visited;
  int i;
  int width;
  int height;
  int wallerror;
  int patherror;
  int recerror;
  int itemserror;
  int roaderror;
  int exit_count;
  int player_count;
  int collectif_count;
  int valid;
  int p_pos_x;
  int p_pos_y;
  int collected;
  int exit_counted;
  int points;
  int fd;
} t_map;

typedef struct s_data {
  int y;
  int x;
  int view;
  int counter;
  void *mlx;
  void *win;
  int width;
  int fd;
  int height;
  int move_count;
  void *textures[5];
  void *player;
  void *exit;
  void *floor;
  void *wall;
  void *coin;
  void *img_ptr;
  void *grid;
  int frames;
  int moves;
  int img_h;
  int img_w;
  t_map *map;
} t_data;
// Checking of map
void ft_chose(t_data *data, int move);
t_map *check_rec(t_map *map);
void ft_plus_fts(t_map *map);
t_map *check_items(t_map *map);
t_map *check_only_items(t_map *map);
int check_path(const char *path);
t_map *flood_fill(t_map *map, char new_char);
int check_map(const char *path, t_map *map);
int check_wall(char **s, int line);
int ft_perror(char *path, t_map *map);
char **fill_line(int fd, int line);
// Drawing of map
int draw_map(t_data *data);
int draw_map2(t_data *data);
int draw_barriers(t_data *data);
int draw_exit(t_data *data);
int draw_barriers(t_data *data);
int draw_floor(t_data *data);
int draw_collectible(t_data *data);
void img_ptr(t_data *data);
// Game play
int put_player(t_data *data);
int move(int keysym, t_data *data);
// Animation
int ft_anim_enem(t_data *data);
// exit
int ft_close_win(t_data *data);
int ft_close_lose(t_data *data);
int close_window(int keysym, t_data *data);
int ft_close(t_data *data);
void ft_invalid_image_p(t_data *data);
void ft_invalid_image(t_data *data);
// utils
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_charchr(char *str, int c);
void ft_free_double_pointer(char **map, int line);
//
int ft_so_long(t_data *data);
// puts
char *ft_itoa(int n);
void ft_valid_move(t_data *data);
void ft_valid_move(t_data *data);
void ft_putstr(const char *s);
void ft_putstr_mlx(t_data *data);
void ft_putchar(char c);
void ft_put_nbr(long nb);
#endif
