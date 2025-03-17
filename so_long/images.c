/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:30:18 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/15 16:42:03 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_set_imgs(char *path, t_data *data, t_img *imgs)
{
	const int	fd = open(path, O_RDONLY, 777);

	if (fd < 0)
	{
		ft_exiterr("Invalid path\n", data, 26, -1);
		exit(1);
	}
	imgs->img = mlx_xpm_file_to_image(data->mlx, path,
			&data->imgs->width, &data->imgs->height);
	if (!imgs->img)
	{
		ft_exiterr("Could not load image\n", data, 21, -1);
	}
	imgs->addr = mlx_get_data_addr(imgs->img, &imgs->bpx, &imgs->line_len,
			&imgs->endian);
	if (imgs->addr == NULL)
	{
		ft_exiterr("Could not get image address\n", data, 22, -1);
	}
}

void	ft_set_all_imgs(t_data *data)
{
	ft_set_imgs("textures/wall.xpm", data, &data->imgs[0]);
	ft_set_imgs("textures/floor.xpm", data, &data->imgs[1]);
	ft_set_imgs("textures/player.xpm", data, &data->imgs[2]);
	ft_set_imgs("textures/coin.xpm", data, &data->imgs[3]);
	ft_set_imgs("textures/exit.xpm", data, &data->imgs[4]);
}
