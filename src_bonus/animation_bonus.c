#include "../include/so_long.h"

int ft_anim_enem(t_data *data) {
  int height;
  int width;

  height = 64;
  width = 64;
  if (data->frames < 20) {
    data->Grid =
        mlx_xpm_file_to_image(data->mlx, "./img/Grid_f.xpm", &width, &height);
  } else if (data->frames < 30) {
    data->Grid =
        mlx_xpm_file_to_image(data->mlx, "./img/Grid2_f.xpm", &width, &height);
  } else if (data->frames < 40) {
    data->Grid =
        mlx_xpm_file_to_image(data->mlx, "./img/Grid3_f.xpm", &width, &height);
  } else if (data->frames < 60) {
    data->Grid =
        mlx_xpm_file_to_image(data->mlx, "./img/Grid4_f.xpm", &width, &height);
  } else if (data->frames < 80) {
    data->Grid =
        mlx_xpm_file_to_image(data->mlx, "./img/Grid5_f.xpm", &width, &height);
    if (data->frames + 1 == 80)
      data->frames = 0;
  }
  data->frames++;
  return 0;
}
