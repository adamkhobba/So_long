#include "../include/so_long.h"

void ft_putchar(char c) { write(1, &c, 1); }

void ft_put_nbr(long nb) {

  if (nb > 9) {
    ft_put_nbr(nb / 10);
    ft_put_nbr(nb % 10);
  } else
    ft_putchar(nb + 48);
}
