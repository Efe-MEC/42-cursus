/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:43:07 by mehcakir          #+#    #+#             */
/*   Updated: 2024/11/03 15:46:45 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int x, int b)
{
	int	i;

	i = 0;
	if (x >= 16)
		i += ft_printhex(x / 16, b);
	if ((x % 16) < 10)
		i += ft_printchar((x % 16) + '0');
	else
	{
		if (b == 0)
			i += ft_printchar((x % 16) + 87);
		else
			i += ft_printchar((x % 16) + 55);
	}
	return (i);
}
