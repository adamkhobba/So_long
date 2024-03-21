#include "../include/so_long.h"

int up(t_data *data) {

  if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] == '0')
    data->map->p_pos_y = data->map->p_pos_y - 1;
  else if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] == 'P') {
    data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] = '0';
    data->map->p_pos_y = data->map->p_pos_y - 1;
  } else if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] ==
             'C') {
    data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] = '0';
    data->map->p_pos_y = data->map->p_pos_y - 1;
    data->map->collected++;
  } else if (data->map->map[data->map->p_pos_y - 1][data->map->p_pos_x] ==
                 'E' &&
             data->map->collected == data->map->collectif_count) {

    data->map->p_pos_y = data->map->p_pos_y - 1;
    ft_close(data);
  }
  draw_map(data);

  return (1);
}

int down(t_data *data) {

  if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] == '0')
    data->map->p_pos_y = data->map->p_pos_y + 1;
  else if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] == 'P') {
    data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] = '0';
    data->map->p_pos_y = data->map->p_pos_y + 1;
  } else if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] ==
             'C') {
    data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] = '0';
    data->map->p_pos_y = data->map->p_pos_y + 1;
    data->map->collected++;
  } else if (data->map->map[data->map->p_pos_y + 1][data->map->p_pos_x] ==
                 'E' &&
             data->map->collected == data->map->collectif_count) {
    data->map->p_pos_y = data->map->p_pos_y + 1;
    ft_close(data);
  }
  draw_map(data);

  return (1);
}

int left(t_data *data) {
  if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] == '0')
    data->map->p_pos_x = data->map->p_pos_x - 1;
  else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] == 'p') {
    data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] = '0';
    data->map->p_pos_x = data->map->p_pos_x - 1;
  } else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] ==
             'C') {
    data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] = '0';
    return (0);
    data->map->p_pos_x = data->map->p_pos_x - 1;
    data->map->collected++;
  } else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x - 1] ==
                 'E' &&
             data->map->collected == data->map->collectif_count) {
    data->map->p_pos_x = data->map->p_pos_x - 1;
    ft_close(data);
  }
  draw_map(data);

  return 1;
}

int right(t_data *data) {

  if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] == '0')
    data->map->p_pos_x = data->map->p_pos_x + 1;
  else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] == 'p') {
    data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] = '0';
    data->map->p_pos_x = data->map->p_pos_x + 1;
  } else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] ==
             'C') {
    data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] = '0';
    data->map->p_pos_x = data->map->p_pos_x + 1;
    data->map->collected++;
  } else if (data->map->map[data->map->p_pos_y][data->map->p_pos_x + 1] ==
                 'E' &&
             data->map->collected == data->map->collectif_count) {

    data->map->p_pos_x = data->map->p_pos_x + 1;
    ft_close(data);
  }
  draw_map(data);
  return (1);
}

int move(int keysym, t_data *data) {
  if (keysym == 13) {
    mlx_clear_window(data->mlx, data->win);
    up(data);
  } else if (keysym == 1) {
    mlx_clear_window(data->mlx, data->win);
    down(data);
  } else if (keysym == 0) {
    mlx_clear_window(data->mlx, data->win);
    left(data);
  } else if (keysym == 2) {
    mlx_clear_window(data->mlx, data->win);
    right(data);
  }
  return (1);
}

int put_player(t_data *data) {

  int width;
  int height;

  width = 64;
  height = 64;
  data->player =
      mlx_xpm_file_to_image(data->mlx, "./img/Character.xpm", &width, &height);
  mlx_put_image_to_window(data->mlx, data->win, data->player,
                          data->map->p_pos_x * PIXEL,
                          data->map->p_pos_y * PIXEL);
  mlx_hook(data->win, 3, (1L << 1), &move, data);
  free(data->player);
  return (1);
}
