/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:51:02 by akhobba           #+#    #+#             */
/*   Updated: 2024/03/28 07:51:04 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

static int	ft_count(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		j;
	long	nbr;

	nbr = n;
	n = 0;
	j = ft_count(nbr);
	p = (char *)malloc(j + 1);
	if (!p)
		return (NULL);
	p[j--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		p[0] = '-';
		n = 1;
	}
	while (j >= n)
	{
		p[j--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (p);
}
