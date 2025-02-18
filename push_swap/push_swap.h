/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:50:56 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/02 18:04:02 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

# define EXIT_SUCCESS 0
# define EXIT_MALLOC_FAILURE 1
# define EXIT_INVALID_ARG 2
# define EXIT_DUPLICATE 3

typedef struct s_stack
{
	size_t	size_a;
	size_t	size_b;
	int		*stack_a;
	int		*stack_b;
	size_t	*target_a;
	size_t	target_b;
	int		*cost;
	int		*rr;
	int		*rrr;
}	t_stack;

void	ft_free_array(char **array);
int		ft_count_token_str(char *str);
char	*ft_join_args(int argc, char **argv);
int		ft_count_args(int argc, char **argv);
bool	ft_is_sorted(const t_stack *stack);
bool	ft_is_circle_sorted(const t_stack *stack);
int		*ft_check_get_args(int argc, char **argv, t_stack *stack);
bool	ft_is_duplicate(const int *array, const size_t lenght);
bool	ft_is_valid_str(const char *str);
void	ft_cal_cost(t_stack *stack);
int		ft_find_max(const t_stack *stack, const char stack_name);
int		ft_find_min(const t_stack *stack, const char stack_name);
size_t	ft_find_index(const t_stack *stack,
			const char stack_name, const int value);
size_t	ft_find_cheapest(const t_stack *stack);
void	ft_exit_free_stack(t_stack *stack, const char *msg, int exit_code);
void	ft_check_init_args(t_stack *stack, int argc, char **argv);
void	ft_pa(t_stack *stack);
void	ft_sa(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rrr(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_move_cheapest_to_top(t_stack *stack);
void	ft_move_b_target_to_top(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_sort_stack(t_stack *stack);
void	ft_sort_more_three(t_stack *stack);
void	ft_set_target_a(t_stack *stack);
void	ft_set_target_b(t_stack *stack);

#endif
