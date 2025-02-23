/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:32:48 by mehcakir          #+#    #+#             */
/*   Updated: 2024/11/14 00:33:20 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(char const *str, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(int nb);
int	ft_printptr(unsigned long p);
int	ft_printuint(unsigned int u);
int	ft_printhex(unsigned int x, int b);

#endif