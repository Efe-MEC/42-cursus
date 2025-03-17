/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:34:28 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/14 23:05:26 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

static void	ft_destroy_img(t_data *data)
{
	int	i;

	if (data->mlx)
	{
		if (data->img && data->img->img)
		{
			mlx_destroy_image(data->mlx, data->img->img);
			ft_free(data->img);
		}
		i = 0;
		while (i < 5)
		{
			if (data->imgs[i].img)
				mlx_destroy_image(data->mlx, data->imgs[i].img);
			i++;
		}
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		ft_free(data->mlx);
	}
}

static void	ft_free_data(t_data *data)
{
	int	i;

	if (data)
	{
		ft_destroy_img(data);
		if (data->key)
			ft_free(data->key);
		if (data->pos)
			ft_free(data->pos);
		i = 0;
		if (data->map)
		{
			while (data->map[i])
				ft_free(data->map[i++]);
			ft_free(data->map);
		}
		ft_free(data);
	}
}

int	ft_exiterr(char *msg, t_data *data, int err, int ret)
{
	if (msg)
	{
		ft_putstr_fd("(", 2);
		ft_putnbr_fd(err, 2);
		ft_putstr_fd(")", 2);
		ft_putstr_fd(msg, 2);
	}
	ft_free_data(data);
	exit(ret);
}

int	ft_exiterrgnl(char *msg, t_data *data, int err, char *line)
{
	free (line);
	if (msg)
	{
		ft_putstr_fd("(", 2);
		ft_putnbr_fd(err, 2);
		ft_putstr_fd(")", 2);
		ft_putstr_fd(msg, 2);
	}
	ft_free_data(data);
	exit(-1);
}
