/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:14:05 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/29 21:14:39 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_data **a, t_data **b)
{
	size_t	len;
	size_t	counter;
	size_t	index;
	int		value;

	counter = 0;
	len = ft_datalstsize(*a);
	while (counter < len - 1)
	{
		index = (*a)->index;
		value = ft_pop(a);
		ft_datalstadd_back(a, ft_datalstnew(value, index));
		counter++;
	}
	counter = 0;
	len = ft_datalstsize(*b);
	while (counter < len - 1)
	{
		index = (*b)->index;
		value = ft_pop(b);
		ft_datalstadd_back(b, ft_datalstnew(value, index));
		counter++;
	}
	ft_putstr_fd("rrr\n", 1);
}

void	ft_rrarrb(t_data **stack, int which)
{
	size_t	len;
	size_t	counter;
	size_t	index;
	int		value;

	counter = 0;
	len = ft_datalstsize(*stack);
	while (counter < len - 1)
	{
		index = (*stack)->index;
		value = ft_pop(stack);
		ft_datalstadd_back(stack, ft_datalstnew(value, index));
		counter++;
	}
	if (which == 1)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	ft_sasb(t_data **stack, int which)
{
	size_t	index1;
	size_t	index2;
	int		value;
	int		value2;
	int		len;

	len = ft_datalstsize(*stack);
	if (len > 2)
	{
		index1 = (*stack)->index;
		value = ft_pop(stack);
		index2 = (*stack)->index;
		value2 = ft_pop(stack);
		ft_push(stack, value, index1);
		ft_push(stack, value2, index2);
	}
	if (which == 1)
		ft_putstr_fd("sa\n", 1);
	else if (which == 2)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_data **a, t_data **b)
{
	int	len;

	len = ft_datalstsize(*a);
	if (len > 2)
		ft_sasb(a, 3);
	len = ft_datalstsize(*b);
	if (len > 2)
		ft_sasb(b, 3);
	ft_putstr_fd("ss\n", 1);
}
