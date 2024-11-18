/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:28:47 by mehcakir          #+#    #+#             */
/*   Updated: 2024/11/14 00:37:51 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long p)
{
	int	i;

	i = 0;
	if (p >= 16)
		i += ft_printptr(p / 16);
	if ((p % 16) < 10)
		i += ft_printchar((p % 16) + '0');
	else
		i += ft_printchar((p % 16) + 87);
	return (i);
}
