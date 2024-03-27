/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:24:24 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/26 14:10:35 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_datalstlast(t_data *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_datalstadd_back(t_data **lst, t_data *new)
{
	t_data	*tmp;

	if (!new || !lst)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		tmp = ft_datalstlast(*lst);
		tmp->next = new;
	}
}

void	ft_datalstadd_front(t_data **lst, t_data *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_data	*ft_datalstnew(int number, size_t index)
{
	t_data	*new;

	new = 0;
	new = malloc(sizeof(t_data));
	if (new == NULL)
		return (NULL);
	if (index > 0)
		new->index = index;
	new->value = number;
	new->next = NULL;
	return (new);
}

void	ft_datalstclear(t_data **lst)
{
	t_data	*tmp;
	t_data	*next;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		tmp->value = 0;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}
