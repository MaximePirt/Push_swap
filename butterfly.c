/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:18:27 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/27 21:08:51 by mpierrot         ###   ########.fr       */
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
	if (how_many > 20 && how_many < 101)
		jz = 20;
	if (how_many > 101)
		jz = 38;
	else
		jz = find_padding(*a);
	sorting_in_execution(a, b, jz);
}

void	sorting_in_execution(t_data **stack_a, t_data **stack_b, size_t padding)
{
	size_t	n_to_move;
	size_t	padding_base;

	padding_base = padding;
	n_to_move = how_much((*stack_a), padding) + 1;
	while ((*stack_a))
	{
		if ((*stack_a)->index <= padding)
		{
			ft_papb(stack_a, stack_b, 2);
			if ((*stack_b)->index > padding - (padding_base / 2))
				ft_rarb(stack_b, 2);
		}
		else
			ft_rarb(stack_a, 1);
		if (ft_datalstsize(*stack_b) == n_to_move)
		{
			padding += padding_base;
			n_to_move += how_much((*stack_a), padding);
		}
	}
	reput_in_a_at_end(stack_a, stack_b);
}

void	reput_in_a_at_end(t_data **stack_a, t_data **stack_b)
{
	while (*stack_b)
		move_biggy_to(stack_a, stack_b, 2);
}
