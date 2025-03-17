/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:39:58 by mehcakir          #+#    #+#             */
/*   Updated: 2024/11/14 00:44:14 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptrext(unsigned long p)
{
	int	i;

	i = 0;
	if (p == 0)
	{
		return (ft_printstr("(nil)"));
	}
	else
	{
		i += ft_printstr("0x");
		i += ft_printptr(p);
	}
	return (i);
}

int	ft_type(char c, va_list arg)
{
	int	p;

	p = 0;
	if (c == 'c')
		p += ft_printchar(va_arg(arg, int));
	else if (c == 's')
		p += ft_printstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		p += ft_printnbr(va_arg(arg, int));
	else if (c == 'u')
		p += ft_printuint(va_arg(arg, unsigned int));
	else if (c == 'x')
		p += ft_printhex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		p += ft_printhex(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		p += ft_printptrext(va_arg(arg, unsigned long));
	}
	else if (c == '%')
		p += ft_printchar('%');
	else
		return (ft_printchar(c));
	return (p);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		check;

	va_start(arg, str);
	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_printchar(str[i]);
			check++;
		}
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			check += ft_type(str[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (check);
}
