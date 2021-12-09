/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:38:44 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/09 17:15:12 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return(0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str || !c)
		return (0);
	while (str[i] != (unsigned char)c && str[i] != '\0')
		i++;
	if (str[i] == (unsigned char)c)
		return (&str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*join;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (0);
	i = -1;
	join = malloc(sizeof(char) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (join == 0)
		return (0);
	while (s1[++i] != '\0')
		join[i] = s1[i];
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		join[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}
