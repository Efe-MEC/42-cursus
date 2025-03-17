/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:56:19 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/13 22:33:47 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] != '1')
	{
		data->pos->x = new_x;
		data->pos->y = new_y;
		data->moves++;
		ft_printf("Moves: %d\n", data->moves);
		if (data->map[data->pos->y][data->pos->x] == 'C')
		{
			data->coin--;
			data->map[data->pos->y][data->pos->x] = '0';
		}
	}
}

void	ft_move_player(t_data *data)
{
	if (data->key->w)
	{
		ft_move(data, data->pos->x, data->pos->y - 1);
		data->key->w = 0;
	}
	if (data->key->a)
	{
		ft_move(data, data->pos->x - 1, data->pos->y);
		data->key->a = 0;
	}
	if (data->key->s)
	{
		ft_move(data, data->pos->x, data->pos->y + 1);
		data->key->s = 0;
	}
	if (data->key->d)
	{
		ft_move(data, data->pos->x + 1, data->pos->y);
		data->key->d = 0;
	}
}

int	ft_gameloop(t_data *data)
{
	ft_draw_map(data);
	ft_draw_player(data);
	ft_key_event(data);
	return (1);
}
