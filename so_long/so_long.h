/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:24:22 by mehcakir          #+#    #+#             */
/*   Updated: 2025/03/15 21:55:33 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"

# define KEY_ESC 65307
# define KEY_EXIT 33
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_check
{
	int		read;
	char	*line;
	int		total_lines;
	int		line_len;
	int		prev_len;
	int		fd;
}			t_check;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpx;
	int		height;
	int		width;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
}			t_key;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		moves;
	int		coin;
	t_key	*key;
	t_pos	*pos;
	t_img	*img;
	t_img	imgs[5];
}			t_data;

typedef struct s_flood
{
	t_data	*data;
	int		**visited;
	int		*collected;
	int		*exit;
}			t_flood;

int		ft_file_check(char *argv, t_data *data);
void	ft_valid_objects(int *nbr, int read, t_data *data, char *line);
int		ft_check_path_to_coin(t_data *data);
t_check	ft_valid_map_file(char *argv, t_data *data);
void	ft_draw_map(t_data *data);
void	ft_draw_player(t_data *data);
int		ft_exiterr(char *msg, t_data *data, int err, int ret);
void	ft_set_all_imgs(t_data *data);
void	ft_check_map(char *argv, t_data *data);
int		ft_key(int keycode, t_data *data);
t_key	*ft_init_keys(void);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);
int		ft_key_event(t_data *data);
int		ft_quit_event(t_data *data);
int		ft_gameloop(t_data *data);
void	ft_move_player(t_data *data);
int		ft_exiterrgnl(char *msg, t_data *data, int err, char *line);

#endif