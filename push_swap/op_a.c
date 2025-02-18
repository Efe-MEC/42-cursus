/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:51:20 by mehcakir          #+#    #+#             */
/*   Updated: 2025/01/29 22:31:15 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *stack)
{
	size_t	i;

	ft_printf("pa\n");
	if (stack->size_b == 0)
		return ;
	i = stack->size_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->size_a++;
	stack->size_b--;
}

void	ft_sa(t_stack *stack)
{
	int	tmp;

	ft_printf("sa\n");
	if (stack->size_a < 2)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
}

void	ft_ra(t_stack *stack)
{
	int		tmp;
	size_t	i;

	ft_printf("ra\n");
	if (stack->size_a < 1)
		return ;
	i = 0;
	tmp = stack->stack_a[0];
	while (i < stack->size_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[stack->size_a - 1] = tmp;
}

void	ft_rra(t_stack *stack)
{
	int		tmp;
	size_t	i;

	ft_printf("rra\n");
	if (stack->size_a <= 1)
		return ;
	i = stack->size_a - 1;
	tmp = stack->stack_a[stack->size_a - 1];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
}
