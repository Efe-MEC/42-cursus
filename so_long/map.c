/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:42:36 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/13 22:22:35 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_import_map(t_data *data, t_check info)
{
	int	i;
	int	j;

	i = 0;
	data->coin = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->coin++;
			if (data->map[i][j] == 'P')
			{
				data->pos->x = j;
				data->pos->y = i;
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	data->map_width = info.line_len;
	data->map_height = info.total_lines;
}

void	ft_check_map(char *argv, t_data *data)
{
	t_check	info;
	int		i;

	i = 0;
	ft_file_check(argv, data);
	info = ft_valid_map_file(argv, data);
	data->map = ft_calloc(info.total_lines + 1, sizeof(char *));
	if (!data->map)
		ft_exiterr("Memory allocation failed\n", data, 7, -1);
	info.fd = open(argv, O_RDWR, 777);
	info.read = 1;
	while (info.read)
	{
		info.read = ft_get_next_line(info.fd, &info.line);
		data->map[i++] = ft_strdup(info.line);
		free(info.line);
	}
	close(info.fd);
	ft_import_map(data, info);
	if (!ft_check_path_to_coin(data))
		ft_exiterr("Can not reach the coins\n", data, 8, -1);
}
