/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:12:07 by mehcakir          #+#    #+#             */
/*   Updated: 2024/10/26 20:28:46 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			last = (char *)s;
		}
		++s;
	}
	if (!(unsigned char)c)
	{
		last = ((char *)s);
	}
	return (last);
}
