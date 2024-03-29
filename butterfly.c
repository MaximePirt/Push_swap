/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:18:27 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/29 20:12:30 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_to_be(t_data **a, t_data **b)
{
	size_t	jz;
	size_t	how_many;

	find_index(*a);
	how_many = ft_datalstsize(*a);
	if (how_many == 2)
		two_num_sort(a);
	if (how_many == 3)
		three_num_sort(a);
	else if (how_many == 4)
		five_four_num_sort(a, b, 4);
	else if (how_many == 5)
		five_four_num_sort(a, b, 5);
	if (how_many <= 5)
		return ;
	if (how_many > 5 && how_many < 100)
		jz = 25;
	if (how_many >= 100 && how_many < 200)
		jz = 35;
	if (how_many > 200)
		jz = 59;
	else
		jz = find_padding(*a);
	sorting_in_execution(a, b, jz);
}

void	reput_in_a_at_end(t_data **stack_a, t_data **stack_b)
{
	size_t	len;
	size_t	countdown;

	len = 0;
	countdown = ft_datalstsize(*stack_b);
	while (*stack_b)
	{
		len++;
		move_biggy_to(stack_a, stack_b, 2);
		countdown--;
		if ((len > 1 && (*stack_a)->index > (*stack_a)->next->index)
			&& (countdown > 1 && (*stack_b)->index < (*stack_b)->next->index))
			ft_ss(stack_a, stack_b);
		else if (len > 1 && (*stack_a)->index > (*stack_a)->next->index)
			ft_sasb(stack_a, 1);
	}
}

void	sorting_in_execution(t_data **stack_a, t_data **stack_b, size_t padding)
{
	size_t	padding_base;

	padding_base = padding;
	while ((*stack_a))
	{
		if ((*stack_a)->index <= padding)
		{
			if (ft_datalstsize(*stack_b) > 1 && ((*stack_b)->index > padding
					- (padding_base / 2)))
				ft_rarb(stack_b, 2);
			ft_papb(stack_a, stack_b, 2);
		}
		else if (ft_datalstsize(*stack_b) > 1 && ((*stack_b)->index > padding
				- (padding_base / 2)))
			ft_rr(stack_a, stack_b);
		else
			ft_rarb(stack_a, 1);
		if (ft_datalstsize(*stack_b) == padding)
			padding += padding_base;
	}
	reput_in_a_at_end(stack_a, stack_b);
}
