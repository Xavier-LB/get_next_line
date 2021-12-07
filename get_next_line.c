/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:47:51 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/07 16:54:01 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int	len;
	int	i;

	i = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	len = read(fd, buffer, BUFFER_SIZE);
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}


#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int	main()
{
	int	fd;
	char	*buff;

	fd = open("Lorem.txt", O_RDONLY);
	buff = get_next_line(fd);
	printf("%s", buff);
	buff = get_next_line(fd);
	printf("%s", buff);
}
