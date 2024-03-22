#include "../include/so_long.h"

int ft_close(t_data *data) {
  mlx_destroy_window(data->mlx, data->win);
  ft_free_double_pointer(data->map->map, data->map->height);
  free(data->mlx);
  exit(0);
  return (0);
}

int close_window(int keysym, t_data *data) {
  if (keysym == 53) {
    mlx_destroy_window(data->mlx, data->win);
    ft_free_double_pointer(data->map->map, data->map->height);
    free(data->mlx);
    exit(0);
  }
  return 0;
}
