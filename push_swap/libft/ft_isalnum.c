/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:07:56 by mehcakir          #+#    #+#             */
/*   Updated: 2024/10/23 14:32:22 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	al;
	int	num;

	al = ft_isalpha(c);
	num = ft_isdigit(c);
	if (al == 1 || num == 1)
	{
		return (1);
	}
	return (0);
}
