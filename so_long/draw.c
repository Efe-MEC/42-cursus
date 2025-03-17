/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:41:47 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/13 22:31:24 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_draw(t_data *data, int x, int y, int i)
{
	const double	img_width = 48;
	const double	img_height = 48;
	double			x_ratio;
	double			y_ratio;

	x_ratio = x * img_width;
	y_ratio = y * img_height;
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[i].img,
		x_ratio, y_ratio);
}

void	ft_draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				ft_draw(data, x, y, 0);
			else if (data->map[y][x] == '0')
				ft_draw(data, x, y, 1);
			else if (data->map[y][x] == 'C')
				ft_draw(data, x, y, 3);
			else if (data->map[y][x] == 'E')
				ft_draw(data, x, y, 4);
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_data *data)
{
	ft_draw(data, data->pos->x, data->pos->y, 2);
}
