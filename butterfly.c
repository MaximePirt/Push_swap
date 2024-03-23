/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:18:27 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/23 06:52:56 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	butterfly_to_be(t_data **a, t_data **b)
// {
// }

void	padding_fly(t_data **a)
{
	size_t	i;

	i = ft_datalstsize(*a);
	if (i < 30)
		return ;
}

void	sorting_in_execution(t_data **stack_a, t_data **stack_b, int padding)
{
	int	i;
	int	a;
	int	len;

	len = ft_datalstsize(*stack_a);
	a = 0;
	i = 0;
	while (*stack_a && (*stack_a)->next)
	{
		i++;
		a++;
		if ((*stack_a)->value <= padding)
		{
			ft_papb(stack_a, stack_b, 2);
			if ((*stack_b)->value >= (padding / 2))
				ft_rarb(stack_b, 2);
		}
		else
			ft_rarb(stack_a, 1);
		if (a == len)
		{
			padding = padding + 20;
			a = 0;
		}
	}
	reput_in_a_at_end(stack_a, stack_b, padding);
}

void	reput_in_a_at_end(t_data **stack_a, t_data **stack_b, int padding)
{
	t_data	*end_of_b;
	t_data	*end_of_a;
	int		i;

	i = 0;
	end_of_b = NULL;
	(void)padding;
	while (*stack_b)
	{
		i++;
		end_of_b = ft_datalstlast(*stack_b);
		end_of_a = ft_datalstlast(*stack_a);
		if ((*stack_b)->value >= end_of_b->value)
			ft_papb(stack_b, stack_a, 1);
		else
		{
			ft_rrarrb(stack_b, 2);
			ft_papb(stack_b, stack_a, 1);
		}
		if ((*stack_a)->value >= (*stack_a)->next->value
			&& (*stack_a)->value <= end_of_a->value)
			ft_sasb(stack_a, 1);
		else if ((*stack_a)->value >= end_of_a->value)
			ft_rarb(stack_a, 1);
	}
}
