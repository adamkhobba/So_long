#include "../include/so_long.h"

int ft_close(t_data *data) {

  mlx_destroy_window(data->mlx, data->win);
  // mlx_destroy_display(data->mlx);
  ft_free_double_pointer(data->map->map, data->map->height);
  free(data->mlx);
  exit(0);
  return (0);
}

int close_window(int keysym, t_data *data) {

  if (keysym == 53) {
    mlx_destroy_window(data->mlx, data->win);
    // mlx_destroy_display(data->mlx);
    ft_free_double_pointer(data->map->map, data->map->height);
    free(data->mlx);
    exit(0);
  }
  return 0;
}

int ft_so_long(t_data *data) {

  data->height = data->map->height * PIXEL;
  data->width = data->map->width * PIXEL;
  data->mlx = mlx_init();
  if (!data->mlx)
    return 0;
  data->win = mlx_new_window(data->mlx, data->width - 64, data->height,
                             "The Old Calse");
  data->map->collected = 0;
  draw_map2(data);
  put_player(data);
  mlx_hook(data->win, 17, (1L << 19), &ft_close, data);
  mlx_hook(data->win, 2, (1L << 0), &close_window, data);
  mlx_loop(data->mlx);
  return 1;
}

int main(int arc, char **arv) {
  t_data data;
  t_map mp;
  int fd;

  data.map = &mp;
  if (!check_map(arv[1], data.map))
    return 0;
  fd = open(arv[1], O_RDWR);
  if (fd < 0)
    return 0;
  data.map->map = fill_line(fd, data.map->height);
  ft_so_long(&data);
  return (0);
}
