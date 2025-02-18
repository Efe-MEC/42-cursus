/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:47:06 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/02 18:05:28 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(const t_stack *stack, const char stack_name)
{
	int		max_value;
	size_t	i;
	int		*stack_tmp;
	size_t	size_tmp;

	i = 0;
	max_value = INT_MIN;
	if (stack_name == 'a')
	{
		stack_tmp = stack->stack_a;
		size_tmp = stack->size_a;
	}
	else
	{
		stack_tmp = stack->stack_b;
		size_tmp = stack->size_b;
	}
	while (i < size_tmp)
	{
		if (stack_tmp[i] > max_value)
			max_value = stack_tmp[i];
		i++;
	}
	return (max_value);
}

int	ft_find_min(const t_stack *stack, const char stack_name)
{
	int		min_value;
	size_t	i;
	int		*stack_tmp;
	size_t	size_tmp;

	i = 0;
	min_value = INT_MAX;
	if (stack_name == 'a')
	{
		stack_tmp = stack->stack_a;
		size_tmp = stack->size_a;
	}
	else
	{
		stack_tmp = stack->stack_b;
		size_tmp = stack->size_b;
	}
	while (i < size_tmp)
	{
		if (stack_tmp[i] < min_value)
			min_value = stack_tmp[i];
		i++;
	}
	return (min_value);
}

size_t	ft_find_index(const t_stack *stack,
		const char stack_name, const int value)
{
	size_t	i;
	int		*stack_tmp;
	size_t	size_tmp;

	i = 0;
	if (stack_name == 'a')
	{
		stack_tmp = stack->stack_a;
		size_tmp = stack->size_a;
	}
	else
	{
		stack_tmp = stack->stack_b;
		size_tmp = stack->size_b;
	}
	while (i < size_tmp)
	{
		if (stack_tmp[i] == value)
			return (i);
		i++;
	}
	return (INT_MAX);
}

size_t	ft_find_cheapest(const t_stack *stack)
{
	size_t	i;
	size_t	cheapest;

	i = 0;
	cheapest = 0;
	while (i < stack->size_a)
	{
		if (stack->cost[i] < stack->cost[cheapest])
			cheapest = i;
		i++;
	}
	return (cheapest);
}
