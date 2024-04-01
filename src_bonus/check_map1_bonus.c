/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:28:52 by akhobba           #+#    #+#             */
/*   Updated: 2024/04/01 20:39:10 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

t_map	*check_rec(t_map *map)
{
	map->i = 1;
	map->width = ft_strlen(map->map[0]);
	while (map->i < map->height - 1)
	{
		if ((size_t)map->width != ft_strlen(map->map[map->i]))
		{
			map->valid = 0;
			map->recerror = 1;
			return (map);
		}
		map->i++;
	}
	if ((size_t)map->width != ft_strlen(map->map[map->height - 1]) && (size_t)map->width
		- 1 != ft_strlen((map->map[map->height - 1])))
	{
		map->valid = 0;
		map->recerror = 1;
	}
	return (map);
}

t_map	*check_items(t_map *map)
{
	map->player_count = 0;
	map->collectif_count = 0;
	map->exit_count = 0;
	map->i = 0;
	while (map->i < map->height - 1)
	{
		map->player_count += ft_charchr(map->map[map->i], 'P');
		map->collectif_count += ft_charchr(map->map[map->i], 'C');
		map->exit_count += ft_charchr(map->map[map->i], 'E');
		map->i++;
	}
	if (map->player_count == 1 && map->collectif_count && map->exit_count == 1)
	{
		map = check_only_items(map);
		if (map->valid == 1)
			return (map);
		else
			map->valid = 0;
	}
	else
		map->valid = 0;
	if (!map->valid)
		map->itemserror = 1;
	return (map);
}

t_map	*check_only_items(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			if (map->map[i][j] == 'P')
			{
				map->p_pos_y = i;
				map->p_pos_x = j;
			}
			if (!(map->map[i][j] == '1' || map->map[i][j] == 'P'
					|| map->map[i][j] == '0' || map->map[i][j] == 'C'
					|| map->map[i][j] == 'E' || map->map[i][j] == 'G'))
				map->valid = 0;
			j++;
		}
		i++;
	}
	return (map);
}

int	check_path(const char *path)
{
	char	*str;
	char	*tmp;
	int		n;

	str = (char *)path;
	tmp = ft_strchr(str, '.');
	n = ft_strlen(tmp);
	if (tmp == str)
		return (0);
	if (ft_strncmp(tmp, ".ber", n) != 0)
		return (0);
	return (1);
}

int	check_wall(char **s, int line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[0][i] != '\n' && s[line - 1][i] != '\n' && s[0][i] && s[line
		- 1][i])
	{
		if (s[0][i] != '1' || s[line - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (s[i] && i < line - 1)
	{
		len = ft_strlen(s[i]);
		if (s[i][0] != '1' || s[i][len - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}
