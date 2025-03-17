/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:30:38 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/13 21:18:07 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*recurs_if(char *line, int depth, int *ret, char *buff)
{
	if (!line)
		return (0);
	line[depth] = 0;
	*ret = 1;
	if (buff[0] == 0)
		*ret = 0;
	return (line);
}

char	*ft_recursiveline(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*line;
	int		test;

	test = read(fd, buff, 1);
	if (test == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == '\0')
	{
		line = malloc(sizeof(char) * (depth + 1));
		return (recurs_if(line, depth, ret, buff));
	}
	else
	{
		line = ft_recursiveline(depth + 1, ret, fd);
		if (!line)
			return (0);
		line[depth] = buff[0];
	}
	return (line);
}

int	ft_get_next_line(int fd, char **line)
{
	int		ret;

	ret = 1;
	*line = ft_recursiveline(0, &ret, fd);
	return (ret);
}
