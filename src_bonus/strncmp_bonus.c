#include "../include/so_long.h"

int ft_strncmp(const char *s1, const char *s2, size_t n) {
  size_t i;

  i = 0;
  while (i < n && (s1[i] != '\0' || s2[i] != '\0')) {
    if (s1[i] != s2[i])
      return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    i++;
  }
  return (0);
}

void ft_valid_move(t_data *data) {
  if (data->map->map[data->map->p_pos_y][data->map->p_pos_x] == 'C' ||
      data->map->map[data->map->p_pos_y][data->map->p_pos_x] == '0') {
    data->frames++;
  }
  ft_putstr_mlx(data);
}

void ft_putstr_mlx(t_data *data) {
  char *str;

  str = ft_itoa(data->frames);
  mlx_string_put(data->mlx, data->win, 64, 64, 0x592690, str);
  free(str);
}
