/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:31:12 by bzelda            #+#    #+#             */
/*   Updated: 2020/11/27 06:05:00 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;
	int		i;

	fd = open("file.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		printf("i = %d %s \n", i, line);
		free(line);
	}
	printf("i = %d %s \n", i, line);
	free(line);
	return (0);
}
