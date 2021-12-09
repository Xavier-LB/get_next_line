/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:47:51 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/09 17:16:46 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "get_next_line_utils.c"


//#include <string.h>
//#include <stdio.h>

char	*get_line(char *stock)
{
	int	i;
	char	*line;

	if (!stock)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{	
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*stocking(char *stock)
{
	char	*str;
	int	i_str;
	int	i_stock;

	i_stock = 0;
	while (stock[i_stock] && stock[i_stock] != '\n')
		i_stock++;
	if (!stock[i_stock])
		return (free(stock), NULL);
	str = ft_calloc(sizeof(char), (ft_strlen(stock) - i_stock + 1));
	if (!str)
		return (NULL);
	i_str = 0;
	while (stock[i_stock])
		str[i_str++] = stock[++i_stock];
	str[i_str] = '\0';
	free(stock);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stock;
	int		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = "";
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);

	len = 1;

	while (len != 0 && !(ft_strchr(buffer, '\n')))
	{
	
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	line = get_line(stock);
	if (!(stock = stocking(stock)))
		return (NULL);
	free(buffer);
	return (line);
}

/*
#include <fcntl.h>

int    main(void)
{
    char    *str;
    int    fd;

    fd = open("Lorem.txt", O_RDONLY);
    if (!fd)
        return (1);
    str = "";
    while ((str = get_next_line(fd)))
    {
        printf("%s", str);
        free(str);
    }
    return (0);
}*/
