/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:22 by mehcakir          #+#    #+#             */
/*   Updated: 2024/10/14 16:45:22 by mehcakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*new_lst;

	if (!lst)
	{
		return ;
	}
	new_lst = lst;
	while (new_lst != NULL)
	{
		(*f)(new_lst->content);
		new_lst = new_lst->next;
	}
}
