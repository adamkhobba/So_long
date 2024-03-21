#include "../include/so_long.h"
int draw_map(t_data *data) {

  // draw_barriers(data);
  // draw_floor(data);
  // draw_collectible(data);
  // draw_exit(data);
  draw_map2(data);
  return (1);
}

int draw_barriers(t_data *data) {
  int y;
  int x;
  int width;
  int height;

  y = 0;
  width = 64;
  height = 64;
  data->wall =
      mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &width, &height);
  if (!data->wall)
    return 0;
  while (y < data->map->height) {
    x = 0;
    while (x < data->map->width) {
      if (data->map->map[y][x] == '1') {
        mlx_put_image_to_window(data->mlx, data->win, data->wall, x * 64,
                                y * 64);
      }
      x++;
    }
    y++;
  }
  free(data->wall);
  return (1);
}

int draw_map2(t_data *data) {
  int y;
  int x;
  int width;
  int height;

  y = 0;
  width = 64;
  height = 64;
  data->wall =
      mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &width, &height);
  data->floor =
      mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &width, &height);
  data->coin =
      mlx_xpm_file_to_image(data->mlx, "./img/coin1.xpm", &width, &height);
  data->exit =
      mlx_xpm_file_to_image(data->mlx, "./img/exit_f.xpm", &width, &height);
  if (!data->wall)
    return 0;
  while (y < data->map->height) {
    x = 0;
    while (x < data->map->width) {
      if (data->map->map[y][x] == '1') {
        mlx_put_image_to_window(data->mlx, data->win, data->wall, x * 64,
                                y * 64);
      }
      if (data->map->map[y][x] == 'C') {
        mlx_put_image_to_window(data->mlx, data->win, data->coin, x * 64,
                                y * 64);
      }
      if (data->map->map[y][x] == 'E') {

        mlx_put_image_to_window(data->mlx, data->win, data->exit, x * 64,
                                y * 64);
      }
      if (data->map->map[y][x] == '0') {
        mlx_put_image_to_window(data->mlx, data->win, data->floor, x * 64,
                                y * 64);
      }
      if (data->map->map[y][x] == 'P') {
        mlx_put_image_to_window(data->mlx, data->win, data->floor, x * 64,
                                y * 64);
      }
      x++;
    }
    y++;
  }
  put_player(data);
  // free(data->wall);
  return (1);
}

int draw_floor(t_data *data) {

  int width;
  int height;
  int y;
  int x;

  width = 64;
  height = 64;
  data->floor =
      mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &width, &height);
  if (!data->floor)
    return 0;
  y = 0;
  while (y < data->map->height) {
    x = 0;
    while (x < data->map->width) {
      if (data->map->map[y][x] != '1') {
        mlx_put_image_to_window(data->mlx, data->win, data->floor, x * 64,
                                y * 64);
      }
      x++;
    }
    y++;
  }
  free(data->floor);
  return (1);
}

int draw_collectible(t_data *data) {

  int width;
  int height;
  int y;
  int x;

  width = 64;
  height = 64;
  data->coin =
      mlx_xpm_file_to_image(data->mlx, "./img/coin1.xpm", &width, &height);
  if (!data->coin)
    return 0;
  y = 0;
  while (y < data->map->height) {
    x = 0;
    while (x < data->map->width) {
      if (data->map->map[y][x] == 'C') {
        mlx_put_image_to_window(data->mlx, data->win, data->coin, x * 64,
                                y * 64);
      }
      x++;
    }
    y++;
  }
  free(data->coin);
  return (1);
}

int draw_exit(t_data *data) {

  int width;
  int height;
  int y;
  int x;

  width = 64;
  height = 64;
  data->exit =
      mlx_xpm_file_to_image(data->mlx, "./img/exit_f.xpm", &width, &height);
  if (!data->exit)
    return 0;
  y = 0;
  while (y < data->map->height) {
    x = 0;
    while (x < data->map->width) {
      if (data->map->map[y][x] == 'E') {
        mlx_put_image_to_window(data->mlx, data->win, data->exit, x * 64,
                                y * 64);
      }
      x++;
    }
    y++;
  }
  free(data->exit);
  return (1);
}
