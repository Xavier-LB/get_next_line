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

char	*get_line(char *stock)
{
	int		i;
	char	*line;

	if (!stock[0])
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
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
	int		i_str;
	int		i_stock;

	i_stock = 0;
	while (stock[i_stock] && stock[i_stock] != '\n')
		i_stock++;
	if (!stock[i_stock])
		return (free(stock), NULL);
	str = malloc(sizeof(char) * (ft_strlen(stock) - i_stock + 1));
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
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	len = 1;
	while (len != 0 && !ft_strchr(stock, '\n'))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (free(buffer), NULL);
		buffer[len] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	line = get_line(stock);
	stock = stocking(stock);
	return (line);
}
