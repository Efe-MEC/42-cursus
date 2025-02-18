/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:58:07 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/02 18:06:02 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_free_stack(t_stack *stack, const char *msg, int exit_code)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack->target_a);
	free(stack->cost);
	free(stack->rr);
	free(stack->rrr);
	free(stack);
	ft_printf("%s", msg);
	exit(exit_code);
}

static void	ft_init_stack(t_stack *stack, int *stack_a, size_t size)
{
	size_t	i;

	i = 0;
	stack->size_a = size;
	stack->size_b = 0;
	stack->stack_a = ft_calloc(size, sizeof(int));
	stack->stack_b = ft_calloc(size, sizeof(int));
	stack->cost = ft_calloc(size, sizeof(int));
	stack->target_a = ft_calloc(size, sizeof(size_t));
	stack->target_b = INT_MAX;
	stack->rr = ft_calloc(size, sizeof(int));
	stack->rrr = ft_calloc(size, sizeof(int));
	if (!stack->stack_a || !stack->stack_b || !stack->cost || !stack->target_a
		|| !stack->rr || !stack->rrr)
		ft_exit_free_stack(stack, "Error\n", EXIT_MALLOC_FAILURE);
	while (i < size)
	{
		stack->stack_a[i] = stack_a[i];
		i++;
	}
	free(stack_a);
}

void	ft_check_init_args(t_stack *stack, int argc, char **argv)
{
	int		*stack_a;
	size_t	size_a;

	stack_a = ft_check_get_args(argc, argv, stack);
	size_a = ft_count_args(argc, argv);
	ft_init_stack(stack, stack_a, size_a);
}
