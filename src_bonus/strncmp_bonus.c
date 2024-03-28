/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:30:36 by akhobba           #+#    #+#             */
/*   Updated: 2024/03/28 08:30:39 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_mlx(t_data *data)
{
	char	*str;

	str = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->win, 64, 64, 0x592690, str);
	free(str);
}

void	ft_int(int *a, int *b, int move)
{
	if (move == 1)
	{
		*a = -1;
		*b = 0;
	}
	if (move == 2)
	{
		*a = +1;
		*b = 0;
	}
	if (move == 3)
	{
		*a = 0;
		*b = +1;
	}
	if (move == 4)
	{
		*a = 0;
		*b = -1;
	}
}

void	ft_chose(t_data *data, int move)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	ft_int(&a, &b, move);
	if (data->map->map[data->map->p_pos_y + a][data->map->p_pos_x + b] == 'E'
		&& data->map->collected == data->map->collectif_count)
	{
		data->map->p_pos_y = data->map->p_pos_y + a;
		data->map->p_pos_x = data->map->p_pos_x + b;
		ft_close_win(data);
	}
	else if (data->map->map[data->map->p_pos_y + a][data->map->p_pos_x
		+ b] == 'G')
	{
		data->map->p_pos_y = data->map->p_pos_y + a;
		data->map->p_pos_x = data->map->p_pos_x + b;
		ft_close_lose(data);
	}
}
