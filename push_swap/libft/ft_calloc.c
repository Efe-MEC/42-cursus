/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:42:02 by mehcakir          #+#    #+#             */
/*   Updated: 2024/10/23 14:30:53 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = (void *)malloc(count * size);
	if (i == NULL)
	{
		return (NULL);
	}
	else
	{
		ft_bzero(i, count * size);
	}
	return (i);
}
