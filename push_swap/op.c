/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:58:04 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/02 18:00:33 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r_to_top(t_stack *stack, const size_t moves)
{
	int		value_a;
	int		value_b;
	size_t	median_a;
	size_t	median_b;

	value_a = stack->stack_a[moves];
	value_b = stack->stack_b[stack->target_a[moves]];
	median_a = stack->size_a / 2;
	median_b = stack->size_b / 2;
	if (stack->size_a % 2 == 1)
		median_a++;
	if (stack->size_b % 2 == 1)
		median_b++;
	if (moves < median_a)
		while (stack->stack_a[0] != value_a)
			ft_ra(stack);
	else
		while (stack->stack_a[0] != value_a)
			ft_rra(stack);
	if (stack->target_a[moves] < median_b)
		while (stack->stack_b[0] != value_b)
			ft_rb(stack);
	else
		while (stack->stack_b[0] != value_b)
			ft_rrb(stack);
}

static void	ft_rr_to_top(t_stack *stack, const size_t moves)
{
	int	value_a;
	int	value_b;

	value_a = stack->stack_a[moves];
	value_b = stack->stack_b[stack->target_a[moves]];
	while (stack->stack_a[0] != value_a && stack->stack_b[0] != value_b)
		ft_rr(stack);
	while (stack->stack_a[0] != value_a)
		ft_ra(stack);
	while (stack->stack_b[0] != value_b)
		ft_rb(stack);
}

static void	ft_rrr_to_top(t_stack *stack, const size_t moves)
{
	int	value_a;
	int	value_b;

	value_a = stack->stack_a[moves];
	value_b = stack->stack_b[stack->target_a[moves]];
	while (stack->stack_a[0] != value_a && stack->stack_b[0] != value_b)
		ft_rrr(stack);
	while (stack->stack_a[0] != value_a)
		ft_rra(stack);
	while (stack->stack_b[0] != value_b)
		ft_rrb(stack);
}

void	ft_move_cheapest_to_top(t_stack *stack)
{
	size_t	moves;

	ft_set_target_a(stack);
	ft_cal_cost(stack);
	moves = ft_find_cheapest(stack);
	if (stack->rr[moves])
		ft_rr_to_top(stack, moves);
	else if (stack->rrr[moves])
		ft_rrr_to_top(stack, moves);
	else
		ft_r_to_top(stack, moves);
}

void	ft_move_b_target_to_top(t_stack *stack)
{
	int		value_a;
	size_t	median_a;
	size_t	moves;

	ft_set_target_b(stack);
	moves = stack->target_b;
	value_a = stack->stack_a[moves];
	median_a = stack->size_a / 2;
	if (stack->size_a % 2 == 1)
		median_a++;
	if (moves < median_a)
	{
		while (stack->stack_a[0] != value_a)
			ft_ra(stack);
	}
	else
	{
		while (stack->stack_a[0] != value_a)
			ft_rra(stack);
	}
}
