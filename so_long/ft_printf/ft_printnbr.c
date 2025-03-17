/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:13:12 by mehcakir          #+#    #+#             */
/*   Updated: 2024/11/03 15:34:17 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printnbr(int nb)
{
	int	i;

	i = 0;
	if (nb >= 0 && nb <= 9)
		i += ft_printchar(nb + '0');
	else if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		i += ft_printchar('-');
		i += ft_printnbr(nb * (-1));
	}
	else
	{
		i += ft_printnbr(nb / 10);
		i += ft_printnbr(nb % 10);
	}
	return (i);
}
