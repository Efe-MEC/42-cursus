/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:22:10 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/02 17:44:28 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(const t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	ft_is_circle_sorted(const t_stack *stack)
{
	size_t	min_index;
	size_t	i;
	size_t	size_a;

	min_index = ft_find_index(stack, 'a', ft_find_min(stack, 'a'));
	i = min_index;
	size_a = stack->size_a;
	while (i != (min_index - 1))
	{
		if (stack->stack_a[i % size_a] > stack->stack_a[(i + 1) % size_a])
			return (false);
		i = (i + 1) % size_a;
	}
	return (true);
}

static int	*ft_convert_str_to_int(const char *str, const size_t num_tokens)
{
	char	**tokens;
	int		*arr;
	size_t	i;

	tokens = ft_split(str, ' ');
	i = 0;
	if (!tokens)
		return (NULL);
	arr = ft_calloc(num_tokens, sizeof(int));
	if (!arr)
	{
		ft_free_array(tokens);
		return (NULL);
	}
	i = 0;
	while (i < num_tokens)
	{
		arr[i] = ft_atoi(tokens[i]);
		i++;
	}
	ft_free_array(tokens);
	return (arr);
}

static char	*ft_check_get_args_util(int argc, char **argv, t_stack *stack)
{
	char	*arg_str;

	if (argc < 2)
		ft_exit_free_stack(stack, "Error\n", EXIT_SUCCESS);
	arg_str = ft_join_args(argc, argv);
	if (!arg_str)
		ft_exit_free_stack(stack, "Error\n", EXIT_MALLOC_FAILURE);
	if (!ft_is_valid_str(arg_str))
	{
		free(arg_str);
		ft_exit_free_stack(stack, "Error\n", EXIT_INVALID_ARG);
	}
	return (arg_str);
}

int	*ft_check_get_args(int argc, char **argv, t_stack *stack)
{
	char	*arg_str;
	size_t	num_tokens;
	int		*arr;

	arg_str = ft_check_get_args_util(argc, argv, stack);
	num_tokens = ft_count_token_str(arg_str);
	arr = ft_convert_str_to_int(arg_str, num_tokens);
	free(arg_str);
	if (!arr)
		ft_exit_free_stack(stack, "Error\n", EXIT_MALLOC_FAILURE);
	if (ft_is_duplicate(arr, num_tokens))
	{
		free(arr);
		ft_exit_free_stack(stack, "Error\n", EXIT_DUPLICATE);
	}
	return (arr);
}
