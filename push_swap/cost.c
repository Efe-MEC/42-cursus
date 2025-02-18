/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:11:14 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/02 17:48:38 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_cal_cost_r(t_stack *stack)
{
	size_t	i;
	size_t	median_a;
	size_t	median_b;

	i = 0;
	median_a = stack->size_a / 2;
	median_b = stack->size_b / 2;
	if (stack->size_a % 2 == 1)
		median_a++;
	if (stack->size_b % 2 == 1)
		median_b++;
	while (i < stack->size_a)
	{
		if (i < median_a)
			stack->cost[i] = i;
		else
			stack->cost[i] = stack->size_a - i;
		if (stack->target_a[i] < median_b)
			stack->cost[i] += stack->target_a[i];
		else
			stack->cost[i] += stack->size_b - stack->target_a[i];
		i++;
	}
}

static void	ft_cal_cost_rr(t_stack *stack)
{
	size_t		i;
	size_t		rr_to_top;
	long long	rest_r_to_top;
	long long	moves;

	i = 0;
	while (i < stack->size_a)
	{
		if (i < stack->target_a[i])
			rr_to_top = i;
		else
			rr_to_top = stack->target_a[i];
		rest_r_to_top = i - stack->target_a[i];
		if (rest_r_to_top < 0)
			rest_r_to_top *= -1;
		moves = rr_to_top + rest_r_to_top;
		if (moves < stack->cost[i])
		{
			stack->cost[i] = moves;
			stack->rr[i] = 1;
		}
		i++;
	}
}

static void	ft_cal_cost_rrr(t_stack *stk)
{
	size_t		i;
	size_t		rrr_to_top;
	long long	rest_rr_to_top;
	long long	moves;

	i = 0;
	while (i < stk->size_a)
	{
		if ((stk->size_a - i) < (stk->size_b - stk->target_a[i]))
			rrr_to_top = stk->size_a - i;
		else
			rrr_to_top = stk->size_b - stk->target_a[i];
		rest_rr_to_top = (stk->size_a - i) - (stk->size_b - stk->target_a[i]);
		if (rest_rr_to_top < 0)
			rest_rr_to_top *= -1;
		moves = rrr_to_top + rest_rr_to_top;
		if (moves < stk->cost[i])
		{
			stk->cost[i] = moves;
			stk->rr[i] = 0;
			stk->rrr[i] = 1;
		}
		i++;
	}
}

void	ft_cal_cost(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size_a)
	{
		stack->rr[i] = 0;
		stack->rrr[i] = 0;
		i++;
	}
	ft_cal_cost_r(stack);
	ft_cal_cost_rr(stack);
	ft_cal_cost_rrr(stack);
}
