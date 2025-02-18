/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:30:07 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/02 17:52:09 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	int	max_value;

	if (stack->size_a > 3)
		return ;
	max_value = ft_find_max(stack, 'a');
	if (stack->stack_a[0] == max_value)
		ft_ra(stack);
	else if (stack->stack_a[1] == max_value)
		ft_rra(stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		ft_sa(stack);
}

void	ft_sort_stack(t_stack *stack)
{
	int		min_value;
	size_t	min_index;
	size_t	median_a;

	min_value = ft_find_min(stack, 'a');
	min_index = ft_find_index(stack, 'a', min_value);
	median_a = stack->size_a / 2;
	if (stack->size_a % 2 == 1)
		median_a += 1;
	if (min_index < median_a)
	{
		while (stack->stack_a[0] != min_value)
			ft_ra(stack);
	}
	else
	{
		while (stack->stack_a[0] != min_value)
			ft_rra(stack);
	}
}

void	ft_sort_more_three(t_stack *stack)
{
	if (stack->size_a > 3)
		ft_pb(stack);
	if (ft_is_circle_sorted(stack))
		ft_sort_stack(stack);
	if (stack->size_a > 3 && !(ft_is_sorted(stack)))
		ft_pb(stack);
	if (ft_is_circle_sorted(stack))
		ft_sort_stack(stack);
	while (stack->size_a > 3 && !(ft_is_sorted(stack)))
	{
		ft_move_cheapest_to_top(stack);
		ft_pb(stack);
		if (ft_is_circle_sorted(stack))
			ft_sort_stack(stack);
	}
	ft_sort_three(stack);
	while (stack->size_b)
	{
		ft_move_b_target_to_top(stack);
		ft_pa(stack);
	}
	ft_sort_stack(stack);
}
