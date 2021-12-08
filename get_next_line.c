/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:47:51 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/08 19:14:01 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"



#include <stdio.h>

char	*get_line(char *stock)
{
	int	i;
	int	len;
	char	*line;

	i = 0;
	len = 0;
	while (stock[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	while (i <= len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	stock = ft_strjoin("", &stock[++len]);
//	printf("%s\n\n", stock);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stock;
	int		len;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);

	len = 1;

	if (stock && ft_strchr(stock, '\n'))
	{
		line = get_line(stock);
	}
	else
	{
		while (len && !(ft_strchr(buffer, '\n')))
		{
			len = read(fd, buffer, BUFFER_SIZE);
			stock = ft_strjoin(stock, buffer);
		}
		line = get_line(stock);
	}
	free(buffer);
	return (line);
}

#include <fcntl.h>

int	main()
{
	int	fd;
	char	*buff;

	fd = open("Lorem.txt", O_RDONLY);
	buff = get_next_line(fd);
	printf("%s", buff);
	buff = get_next_line(fd);
	printf("%s", buff);
//	buff = get_next_line(fd);
//	printf("%s", buff);
}
