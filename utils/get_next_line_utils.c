/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:33:02 by akhobba           #+#    #+#             */
/*   Updated: 2024/01/28 18:31:36 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	l1;
	size_t	l2;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!p)
		return (NULL);
	ft_strcpy(p, s1);
	i = 0;
	while (s2[i])
	{
		p[l1++] = s2[i++];
	}
	p[l1] = '\0';
	free(s1);
	return (p);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	char	*put;
	size_t	i;

	i = 0;
	ptr = (char *)s;
	put = (char *)malloc(ft_strlen(s) + 1);
	if (put == NULL)
		return ((void *)0);
	while (ptr[i])
	{
		put[i] = ptr[i];
		i++;
	}
	put[i] = '\0';
	return (put);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	j;

	j = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[start] && j < len)
	{
		ptr[j++] = s[start++];
	}
	ptr[j] = '\0';
	return (ptr);
}
