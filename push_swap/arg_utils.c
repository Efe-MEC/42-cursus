/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:30:44 by mehcakir          #+#    #+#             */
/*   Updated: 2025/02/02 17:53:29 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_count_token_str(char *str)
{
	size_t	num_tokens;
	char	**token;

	num_tokens = 0;
	token = ft_split(str, ' ');
	if (!token)
		return (num_tokens);
	while (token[num_tokens] != NULL)
		num_tokens++;
	ft_free_array(token);
	return (num_tokens);
}

char	*ft_join_args(int argc, char **argv)
{
	char	*sep_str;
	char	*args_with_sep;
	char	*tmp;
	int		i;

	sep_str = " ";
	i = 1;
	while (i < argc)
	{
		args_with_sep = ft_strjoin(argv[i], " ");
		if (!args_with_sep && i != 1)
		{
			free(sep_str);
			return (NULL);
		}
		tmp = sep_str;
		sep_str = ft_strjoin(sep_str, args_with_sep);
		free(args_with_sep);
		if (i != 1)
			free(tmp);
		if (!sep_str)
			return (NULL);
		i++;
	}
	return (sep_str);
}

int	ft_count_args(int argc, char**argv)
{
	char	*args_str;
	size_t	num_tokens;

	args_str = ft_join_args(argc, argv);
	num_tokens = ft_count_token_str(args_str);
	free(args_str);
	return (num_tokens);
}
