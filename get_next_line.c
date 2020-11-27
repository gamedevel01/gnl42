/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:24:58 by bzelda            #+#    #+#             */
/*   Updated: 2020/11/27 05:42:28 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*bumpfunc(char *str)
{
	size_t	tempo;
	char	*res;

	tempo = 0;
	while (str[tempo] != '\n')
		tempo++;
	res = ft_memmalloc(tempo + 1);
	res[tempo] = '\0';
	return (res);
}

char	*ft_strchr(char *s1, int s2)
{
	size_t tempo;

	tempo = 0;
	while (s1[tempo])
	{
		if (s1[tempo] == (char)s2)
			return (&s1[tempo]);
		tempo++;
	}
	return (&s1[tempo]);
}

int		get_next_line(int const fd, char **line)
{
	static char *str = NULL;
	char		*tempo;
	char		*buffer;
	int			result;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000)
		return (-1);
	if (str == NULL)
		str = ft_memmalloc(BUFF_SIZE);
	buffer = ft_memmalloc(BUFF_SIZE + 1);
	tempo = ft_strncpy(ft_memmalloc(BUFF_SIZE), str, BUFF_SIZE);
	while (!ft_strchr(tempo, '\n'))
	{
		if ((result = read(fd, buffer, BUFF_SIZE)) < 1)
			return (line_verif(line, &tempo, result, &str));
		buffer[result] = '\0';
		tempo = ft_strconcat(tempo, buffer);
	}
	*line = bumpfunc(tempo);
	if (ft_strchr(tempo, '\n'))
		str = ft_strncpy(str, ft_strchr(tempo, '\n') + 1, BUFF_SIZE);
	free(tempo);
	free(buffer);
	return (1);
}
