/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:23:18 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/14 23:25:15 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit_event(t_data *data)
{
	ft_exiterr("Exit\n", data, 24, 0);
	mlx_do_key_autorepeaton(data->mlx);
	return (0);
}

static void	ft_start_game(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, data->map_width * 48,
			data->map_height * 48);
	if (!data->img->img)
		ft_exiterr("Img faild\n", data, 7, -1);
	data->win = mlx_new_window(data->mlx, data->map_width * 48,
			data->map_height * 48, "so_long");
	if (!data->win)
		ft_exiterr("Window failed\n", data, 8, -1);
	ft_set_all_imgs(data);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpx,
			&data->img->line_len, &data->img->endian);
	if (!data->img->addr)
		ft_exiterr("Img failed\n", data, 9, -1);
	data->img->width = 1000;
	data->img->height = 1000;
	data->moves = 0;
	mlx_hook(data->win, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->win, 3, 1L << 1, ft_key_release, data);
	mlx_hook(data->win, KEY_EXIT, 1L << 2, ft_quit_event, data);
	mlx_loop_hook(data->mlx, ft_gameloop, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_exiterr("Invalid arguments\n", NULL, 1, -1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_exiterr("Memory allocation failed\n", data, 2, -1);
	data->pos = ft_calloc(1, sizeof(t_pos));
	if (!data->pos)
		ft_exiterr("Memory allocation failed\n", data, 3, -1);
	data->key = ft_init_keys();
	if (!data->key)
		ft_exiterr("Memory allocation failed\n", data, 4, -1);
	ft_check_map(argv[1], data);
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		ft_exiterr("Memory allocation failed\n", data, 5, -1);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exiterr("Memory allocation failed\n", data, 6, -1);
	ft_start_game(data);
	return (0);
}
