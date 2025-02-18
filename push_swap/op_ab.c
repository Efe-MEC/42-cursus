/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:39:38 by mehcakir          #+#    #+#             */
/*   Updated: 2025/01/29 22:47:26 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack *stack)
{
	int	tmp;

	ft_printf("ss\n");
	if (stack->size_a >= 2)
	{
		tmp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = tmp;
	}
	if (stack->size_b >= 2)
	{
		tmp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = tmp;
	}
}

static void	ft_rr_util(int *stack, size_t size)
{
	int		tmp;
	size_t	i;

	if (size < 2)
		return ;
	tmp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}

void	ft_rr(t_stack *stack)
{
	ft_printf("rr\n");
	ft_rr_util(stack->stack_a, stack->size_a);
	ft_rr_util(stack->stack_b, stack->size_b);
}

static void	ft_rrr_util(int *stack, size_t size)
{
	int		tmp;
	size_t	i;

	if (size < 2)
		return ;
	tmp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	ft_rrr(t_stack *stack)
{
	ft_printf("rrr\n");
	ft_rrr_util(stack->stack_a, stack->size_a);
	ft_rrr_util(stack->stack_b, stack->size_b);
}
