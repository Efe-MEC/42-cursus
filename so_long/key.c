/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:34:03 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/14 23:30:50 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_key	*ft_init_keys(void)
{
	t_key	*keys;

	keys = malloc(sizeof(t_key));
	if (!keys)
		return (NULL);
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	return (keys);
}

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC || keycode == KEY_EXIT)
		ft_exiterr("Exit\n", data, 23, 0);
	else if ((keycode == KEY_W || keycode == KEY_UP)
		&& data->key->w == 0)
		data->key->w = 1;
	else if ((keycode == KEY_A || keycode == KEY_LEFT)
		&& data->key->a == 0)
		data->key->a = 1;
	else if ((keycode == KEY_S || keycode == KEY_DOWN)
		&& data->key->s == 0)
		data->key->s = 1;
	else if ((keycode == KEY_D || keycode == KEY_RIGHT)
		&& data->key->d == 0)
		data->key->d = 1;
	return (1);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == KEY_ESC || keycode == KEY_EXIT)
		ft_exiterr("Exit\n", data, 24, 0);
	else if ((keycode == KEY_W || keycode == KEY_UP)
		&& data->key->w == 1)
		data->key->w = 0;
	else if ((keycode == KEY_A || keycode == KEY_LEFT)
		&& data->key->a == 1)
		data->key->a = 0;
	else if ((keycode == KEY_S || keycode == KEY_DOWN)
		&& data->key->s == 1)
		data->key->s = 0;
	else if ((keycode == KEY_D || keycode == KEY_RIGHT)
		&& data->key->d == 1)
		data->key->d = 0;
	return (1);
}

int	ft_key_event(t_data *data)
{
	if (data->coin == 0 && data->map[data->pos->y][data->pos->x] == 'E')
		ft_exiterr("You won!\n", data, 25, 0);
	else
		ft_move_player(data);
	return (1);
}
