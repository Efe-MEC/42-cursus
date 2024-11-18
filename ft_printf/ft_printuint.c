/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:37:45 by mehcakir          #+#    #+#             */
/*   Updated: 2024/11/03 15:36:13 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int u)
{
	int	i;

	i = 0;
	if (u <= 9)
		i += ft_printchar(u + '0');
	else
	{
		i += ft_printuint(u / 10);
		i += ft_printuint(u % 10);
	}
	return (i);
}
