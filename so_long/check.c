/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:47:52 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/15 21:54:48 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_map_walls(char *line, int wall, int len, t_data *data)
{
	int	i;

	i = 0;
	if (wall == 1)
	{
		while (line[i])
		{
			if (line[i] != '1')
				ft_exiterrgnl("Invalid map(wall)\n", data, 13, line);
			i++;
		}
	}
	else
	{
		if (line[i] != '1' || line[len - 1] != '1')
			ft_exiterrgnl("Invalid map(wall)\n", data, 14, line);
	}
	return (1);
}

static int	ft_valid_map_chars(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
		{
			ft_exiterrgnl("Invalid character\n", data, 12, line);
		}
		i++;
	}
	return (1);
}

static int	ft_count_objects(char *line, int read, t_data *data)
{
	static int	c[3] = {0};
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			c[0]++;
		else if (line[i] == 'P')
			c[1]++;
		else if (line[i] == 'E')
			c[2]++;
		i++;
	}
	ft_valid_objects(c, read, data, line);
	return (1);
}

static void	ft_valid_lines(t_check *info, t_data *data)
{
	while (info->read > 0)
	{
		info->prev_len = info->line_len;
		info->read = ft_get_next_line(info->fd, &info->line);
		info->line_len = ft_strlen(info->line);
		if (info->prev_len != -1 && info->prev_len != info->line_len)
			ft_exiterrgnl("Invalid map\n", data, 11, info->line);
		ft_count_objects(info->line, info->read, data);
		ft_valid_map_chars(info->line, data);
		if (info->total_lines++ == 0 || info->read == 0)
			ft_map_walls(info->line, 1, info->line_len, data);
		else
			ft_map_walls(info->line, 0, info->line_len, data);
		free(info->line);
	}
}

t_check	ft_valid_map_file(char *argv, t_data *data)
{
	t_check	info;

	ft_bzero(&info, sizeof(t_check));
	info.line_len = -1;
	info.read = 1;
	info.fd = open(argv, O_RDWR, 777);
	if (info.fd < 0)
		ft_exiterr("File not found\n", data, 10, -1);
	ft_valid_lines(&info, data);
	close(info.fd);
	return (info);
}
