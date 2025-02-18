/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:51:52 by mehcakir          #+#    #+#             */
/*   Updated: 2025/01/29 22:57:56 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
	{
		ft_printf("Error\n");
		exit(EXIT_MALLOC_FAILURE);
	}
	ft_check_init_args(stack, argc, argv);
	if (!ft_is_sorted(stack))
	{
		if (stack->size_a == 2)
			ft_sa(stack);
		else if (stack->size_a == 3)
			ft_sort_three(stack);
		else if (ft_is_circle_sorted(stack))
			ft_sort_stack(stack);
		else
			ft_sort_more_three(stack);
	}
	ft_exit_free_stack(stack, "", EXIT_SUCCESS);
}
