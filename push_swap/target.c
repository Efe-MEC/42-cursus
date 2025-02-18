/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:58:14 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/03 21:33:13 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_target_a(t_stack *stk)
{
	size_t	i;
	size_t	j;
	size_t	target;

	i = 0;
	while (i < stk->size_a)
	{
		target = INT_MAX;
		j = 0;
		while (j < stk->size_b)
		{
			if (stk->stack_b[j] < stk->stack_a[i])
			{
				if (stk->stack_b[j] < stk->stack_a[i] && (target == INT_MAX
						|| stk->stack_b[j] > stk->stack_b[target]))
					target = j;
			}
			j++;
		}
		if (target == INT_MAX)
			stk->target_a[i] = ft_find_index(stk, 'b', ft_find_max(stk, 'b'));
		else
			stk->target_a[i] = target;
		i++;
	}
}

void	ft_set_target_b(t_stack *stack)
{
	size_t	i;
	size_t	target;

	target = INT_MAX;
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] > stack->stack_b[0] && (target == INT_MAX
				|| stack->stack_a[i] < stack->stack_a[target]))
			target = i;
		i++;
	}
	if (target == INT_MAX)
		stack->target_b = ft_find_index(stack, 'a', ft_find_min(stack, 'a'));
	else
		stack->target_b = target;
}
