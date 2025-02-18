/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:33:32 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/03 21:38:26 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_duplicate(const int *array, const size_t lenght)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!array || lenght <= 0)
		return (true);
	while (i < lenght - 1)
	{
		j = i + 1;
		while (j < lenght)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	ft_is_numric(const char *token)
{
	if (*token >= '0' && *token <= '9')
	{
		while (*token)
		{
			if (!(*token >= '0' && *token <= '9'))
				return (false);
			token++;
		}
		return (true);
	}
	else if (*token == '-' || *token == '+')
	{
		token++;
		if (*token == '\0' || !(*token >= '0' && *token <= '9'))
			return (false);
		while (*token)
		{
			if (!(*token >= '0' && *token <= '9'))
				return (false);
			token++;
		}
		return (true);
	}
	else
		return (false);
}

static bool	ft_is_zero(const char *token)
{
	bool	is_zero;

	is_zero = (ft_strncmp(token, "0", 2)
			|| ft_strncmp(token, "+0", 3)
			|| ft_strncmp(token, "-0", 3));
	return (is_zero);
}

static bool	ft_is_value_overflow(const char *token)
{
	int	sign;
	int	value;
	int	digit;

	sign = 1;
	value = 0;
	if (*token == '-')
	{
		sign = -1;
		token++;
	}
	else if (*token == '+')
		token++;
	while (*token >= '0' && *token <= '9')
	{
		digit = *token - '0';
		if ((sign == 1 && (value > INT_MAX / 10
					|| (value == INT_MAX / 10 && digit > INT_MAX % 10)))
			|| (sign == -1 && (value > -(INT_MIN / 10)
					|| (value == -(INT_MIN / 10) && digit > -(INT_MIN % 10)))))
			return (true);
		value = value * 10 + digit;
		token++;
	}
	return (false);
}

bool	ft_is_valid_str(const char *str)
{
	char	**tokens;
	size_t	i;
	int		value;

	tokens = ft_split(str, ' ');
	i = 0;
	if (!tokens)
		return (false);
	while (tokens[i])
	{
		value = ft_atoi(tokens[i]);
		if ((value == 0 && !ft_is_zero(tokens[i]))
			|| !ft_is_numric(tokens[i])
			|| ft_is_value_overflow(tokens[i]))
		{
			ft_free_array(tokens);
			return (false);
		}
		i++;
	}
	ft_free_array(tokens);
	return (true);
}
