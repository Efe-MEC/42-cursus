/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:31:44 by mehcakir          #+#    #+#             */
/*   Updated: 2025/01/29 22:39:16 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack *stack)
{
	size_t	i;

	ft_printf("pb\n");
	if (stack->size_a == 0)
		return ;
	i = stack->size_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->size_b++;
	stack->size_a--;
}

void	ft_sb(t_stack *stack)
{
	int	tmp;

	ft_printf("sb\n");
	if (stack->size_b < 2)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
}

void	ft_rb(t_stack *stack)
{
	int		tmp;
	size_t	i;

	ft_printf("rb\n");
	if (stack->size_b < 1)
		return ;
	i = 0;
	tmp = stack->stack_b[0];
	while (i < stack->size_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[stack->size_b - 1] = tmp;
}

void	ft_rrb(t_stack *stack)
{
	int		tmp;
	size_t	i;

	ft_printf("rrb\n");
	if (stack->size_b <= 1)
		return ;
	i = stack->size_b - 1;
	tmp = stack->stack_b[stack->size_b - 1];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
}
