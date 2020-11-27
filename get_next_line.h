/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 03:24:16 by bzelda            #+#    #+#             */
/*   Updated: 2020/11/27 06:01:25 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 10

int		get_next_line(int const fd, char **line);
int		line_verif(char **line, char **tmp, int res, char **str);
char	*ft_strncpy(char *dst, char const *src, size_t count);
char	*ft_memmalloc(size_t size);
char	*ft_strconcat(char *str1, char *str2);
char	*bumpfunc(char *str);
char	*ft_strchr(char *s1, int s2);
int		get_next_line(int const fd, char **line);

#endif
