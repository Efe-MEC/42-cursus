/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:10:09 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/22 01:48:07 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag = 0;

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	final;

	i = 0;
	sign = 1;
	final = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = final * 10 + str[i] - '0';
		i++;
	}
	return (final * sign);
}

void	ft_flg_change(int SIGUSR)
{
	(void)SIGUSR;
	if (SIGUSR == SIGUSR1)
		g_flag = 1;
}

void	ft_send_char(int server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (!g_flag)
			;
		g_flag = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0 || kill(server_pid, 0) == -1)
		{
			ft_printf("Invalid PID\n");
			return (0);
		}
		signal(SIGUSR1, ft_flg_change);
		i = -1;
		while (argv[2][++i])
			ft_send_char(server_pid, argv[2][i]);
		ft_send_char(server_pid, '\0');
	}
}
