#include "../include/so_long.h"

void ft_putchar(char c) {
  write(1, &c, 1);
  return;
}

void ft_putstr(const char *s) {
  int i;

  i = 0;
  while (s[i]) {
    ft_putchar(s[i]);
    i++;
  }
  return;
}
void ft_put_nbr(long nb) {

  if (nb > 9) {
    ft_put_nbr(nb / 10);
    ft_put_nbr(nb % 10);
  } else
    ft_putchar(nb + 48);
  return;
}
