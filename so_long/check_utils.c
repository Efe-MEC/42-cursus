/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:27:31 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/15 16:29:07 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_check(char *argv, t_data *data)
{
	char	*c;

	c = ft_strrchr(argv, '.');
	if (!c || ft_strncmp(c, ".ber", ft_strlen(argv)) != 0)
		ft_exiterr("Invalid file\n", data, 14, -1);
	if (argv[ft_strlen(argv) - 5] == '/' || ft_strlen(argv) <= 4)
		ft_exiterr("Invalid file\n", data, 14, -1);
	return (1);
}

void	ft_valid_objects(int *nbr, int read, t_data *data, char *line)
{
	if (!read)
	{
		if (nbr[0] < 1 || nbr[1] != 1 || nbr[2] != 1)
			ft_exiterrgnl("Invalid map\n", data, 15, line);
	}
}

static void	ft_flood_fill(int y, int x, t_flood *flood)
{
	if (y < 0 || x < 0 || y >= flood->data->map_height
		|| x >= flood->data->map_width)
		return ;
	if (flood->visited[y][x] || flood->data->map[y][x] == '1')
		return ;
	flood->visited[y][x] = 1;
	if (flood->data->map[y][x] == 'C')
		(*flood->collected)++;
	if (flood->data->map[y][x] == 'E')
		*flood->exit = 1;
	ft_flood_fill(y + 1, x, flood);
	ft_flood_fill(y - 1, x, flood);
	ft_flood_fill(y, x + 1, flood);
	ft_flood_fill(y, x - 1, flood);
}

static int	**allocate_visited(t_data *data)
{
	int	**visited;
	int	i;

	visited = ft_calloc(data->map_height, sizeof(int *));
	if (!visited)
		ft_exiterr("Memory allocation failed\n", data, 16, -1);
	i = 0;
	while (i < data->map_height)
	{
		visited[i] = ft_calloc(data->map_width, sizeof(int));
		if (!visited[i])
			ft_exiterr("Memory allocation failed\n", data, 17, -1);
		i++;
	}
	return (visited);
}

int	ft_check_path_to_coin(t_data *data)
{
	int		**visited;
	int		collected;
	int		exit;
	int		i;
	t_flood	flood;

	visited = allocate_visited(data);
	if (!visited)
		ft_exiterr("Memory allocation failed\n", data, 18, -1);
	collected = 0;
	exit = 0;
	flood.data = data;
	flood.visited = visited;
	flood.collected = &collected;
	flood.exit = &exit;
	ft_flood_fill(data->pos->y, data->pos->x, &flood);
	i = 0;
	while (i < data->map_height)
		free(visited[i++]);
	free(visited);
	if (collected != data->coin)
		ft_exiterr("Invalid map\n", data, 19, -1);
	if (!exit)
		ft_exiterr("Invalid map\n", data, 20, -1);
	return (1);
}
