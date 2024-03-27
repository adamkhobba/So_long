#include "../include_bonus/so_long_bonus.h"

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

void ft_putstr_mlx(t_data *data) {
  char *str;

  str = ft_itoa(data->mover_count);
  mlx_string_put(data->mlx, data->win, 64, 64, 0x592690, str);
  free(str);
}
