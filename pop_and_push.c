/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_and_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:12:16 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/29 21:13:15 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pop(t_data **stack)
{
	int		value;
	t_data	*tmp;

	value = (*stack)->value;
	tmp = (*stack)->next;
	free(*stack);
	(*stack) = tmp;
	return (value);
}

int	ft_pop_end(t_data **stack)
{
	int		value;
	t_data	*tmp;
	t_data	*prev;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	value = tmp->value;
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
	return (value);
}

void	ft_push(t_data **stack, int value, size_t index)
{
	ft_datalstadd_front(stack, ft_datalstnew(value, index));
}
