/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:25:01 by bzelda            #+#    #+#             */
/*   Updated: 2020/11/27 06:03:00 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	size_t tempo;

	tempo = 0;
	while (str[tempo])
		tempo++;
	return (tempo);
}

int		line_verif(char **line, char **tmp, int res, char **str)
{
	*str = NULL;
	if (res == 0 && ft_strlen(*tmp) > 0)
	{
		*line = *tmp;
		*tmp = NULL;
		return (1);
	}
	return (res);
}

char		*ft_strncpy(char *dst, char const *src, size_t count)
{
	size_t	tempo;

	tempo = 0;
	while (tempo < count && src[tempo])
	{
		dst[tempo] = src[tempo];
		tempo++;
	}
	while (tempo < count && dst[tempo])
	{
		dst[tempo] = '\0';
	}
	return (dst);
}

char		*ft_memmalloc(size_t size)
{
	char	*res;

	if (!(res = malloc(size * sizeof(char))))
		return (NULL);
	while (size)
	{
		res[size] = '\0';
		size--;
	}
	return (res);
}

char		*ft_strconcat(char *str1, char *str2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(res = ft_memmalloc(ft_strlen(str1) + ft_strlen(str2))))
		return (NULL);
	while (str1[i])
		res[i] = str1[i];
	i++;
	while (str2[j])
	{
		res[i + j] = str2[j];
		j++;
	}
	return (res);
}
