/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:01:54 by mehcakir          #+#    #+#             */
/*   Updated: 2024/10/25 16:24:15 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || !len)
	{
		return (dst);
	}
	else if (dst < src)
	{
		while (i < len)
		{
			*((unsigned char *) dst + i) = *((unsigned char *) src + i);
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			*((unsigned char *) dst + len) = *((unsigned char *) src + len);
		}
	}
	return (dst);
}
