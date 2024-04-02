/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:17:36 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/02 12:52:03 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_index(t_data **stack)
{
	int		index;
	t_data	*tmp;
	t_data	*prev;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	index = tmp->index;
	if (!prev)
	{
		free(tmp);
		*stack = NULL;
	}
	else
	{
		prev->next = NULL;
		free(tmp);
	}
	return (index);
}

int	check_index(t_data *stack)
{
	t_data	*tmp;
	t_data	*before;

	before = stack;
	tmp = before->next;
	while (before && before->next)
	{
		if (before->index >= tmp->index)
			return (1);
		before = before->next;
		tmp = tmp->next;
	}
	return (0);
}

void	is_it_sort(t_data *a)
{
	int	i;

	i = check_index(a);
	if (i == 0)
		ft_free_all(NULL, &a, NULL, 1);
}
