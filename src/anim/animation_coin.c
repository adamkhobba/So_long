#include "../../include/so_long.h"

void ft_anim_exit(t_data *data, int x, int y) {
  int width;
  int height;

  width = 64;
  height = 64;
  data->exit = mlx_xpm_file_to_image(data->mlx, "", &width, &height);
  mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
  return;
}
