/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:10:13 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/23 12:55:09 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int SIGUSR, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 0;

	(void)context;
	if (SIGUSR == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("\nMessage received\n");
		}
		else
		{
			ft_printf("%c", c);
		}
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_handler;
	act.sa_flags = SA_SIGINFO;
	ft_printf("Server is running\n");
	if (sigaction(SIGUSR1, &act, NULL) == -1
		|| sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
