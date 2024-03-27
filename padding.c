/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:59:16 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/27 17:51:56 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_data **id_stack, t_data *support)
{
	t_data	*start;
	t_data	*check;
	t_data	*check_start;
	size_t	i;

	i = 1;
	check = *id_stack;
	check_start = check;
	start = support;
	while (support)
	{
		check = check_start;
		while (check)
		{
			if (support->value == check->value)
			{
				check->index = i;
				i++;
			}
			check = check->next;
		}
		support = support->next;
	}
}

void	ft_datalstcpy(t_data *give, t_data **copy)
{
	size_t	index;

	*copy = NULL;
	while (give != NULL)
	{
		index = give->index;
		ft_datalstadd_back(copy, ft_datalstnew(give->value, index));
		give = give->next;
	}
}

void	find_index(t_data *a)
{
	t_data	*tmp_a;

	tmp_a = NULL;
	ft_datalstcpy(a, &tmp_a);
	sort_the_copy(&tmp_a);
	indexation(&a, tmp_a);
	ft_free_all(NULL, &tmp_a, NULL, 0);
}

void	padding_fly(t_data **a)
{
	size_t	i;

	i = ft_datalstsize(*a);
	if (i < 30)
		return ;
}

void	sort_the_copy(t_data **stack)
{
	t_data *start;
	t_data *check;
	int swap;

	check = *stack;
	start = check;
	while (start)
	{
		check = start;
		while (check)
		{
			if (start->value > check->value)
			{
				swap = start->value;
				start->value = check->value;
				check->value = swap;
			}
			check = check->next;
		}
		start = start->next;
	}
}