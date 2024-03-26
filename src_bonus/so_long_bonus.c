#include "../include_bonus/so_long_bonus.h"

int ft_so_long(t_data *data) {

  data->height = data->map->height * PIXEL;
  data->width = data->map->width * PIXEL;
  data->mlx = mlx_init();
  if (!data->mlx)
    return 0;
  data->win = mlx_new_window(data->mlx, data->width - 64, data->height,
                             "The Old Calse");
  data->map->collected = 0;
  data->view = 2;
  data->mover_count = 0;
  img_ptr(data);
  draw_map(data);
  put_player(data);
  mlx_hook(data->win, 17, (1L << 19), &ft_close, data);
  mlx_hook(data->win, 3, (1L << 0), &close_window, data);
  mlx_loop(data->mlx);
  return 1;
}

int main(int arc, char **arv) {
  t_data data;
  t_map mp;
  int fd;

  data.map = &mp;

  ft_perror(arv[1], data.map);
  // printf("%d", check_map(arv[1], data.map));
  fd = open(arv[1], O_RDWR);
  if (fd < 0)
    return 0;
  data.map->map = fill_line(fd, data.map->height);
  ft_so_long(&data);
  return (0);
}
