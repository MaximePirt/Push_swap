/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:03:34 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/29 21:10:00 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_biggy_to(t_data **take, t_data **stack, int which)
{
	size_t	biggy_position;
	size_t	biggy;
	size_t	len;
	int		i;

	biggy = find_biggy(*stack, 1);
	biggy_position = find_biggy(*stack, 2);
	len = ft_datalstsize(*stack);
	if (biggy_position <= (len / 2))
	{
		while ((*stack)->index != biggy)
		{
			i = move_biggy_r(take, stack, biggy, which);
			if (i == -1)
				return ;
		}
	}
	while ((*stack)->index != biggy)
	{
		i = move_biggy_rr(take, stack, biggy, which);
		if (i == -1)
			return ;
	}
	ft_papb(stack, take, 1);
}

int	move_biggy_r(t_data **take, t_data **stack, size_t biggy, int which)
{
	if ((*stack)->next->index == biggy && (*stack)->index == biggy - 1)
	{
		ft_papb(stack, take, 1);
		ft_papb(stack, take, 1);
		if ((*stack)->next->index == biggy && (*stack)->index == biggy - 1)
			ft_ss(take, stack);
		else
			ft_sasb(take, 1);
		return (-1);
	}
	else if ((*stack)->index == biggy - 1)
	{
		ft_papb(stack, take, 1);
		while ((*stack)->index != biggy)
			ft_rarb(stack, which);
		ft_papb(stack, take, 1);
		ft_sasb(take, 1);
		return (-1);
	}
	ft_rarb(stack, which);
	return (0);
}

int	move_biggy_rr(t_data **take, t_data **stack, size_t biggy, int which)
{
	if ((*stack)->next->index == biggy && (*stack)->index == biggy - 1)
	{
		ft_papb(stack, take, 1);
		ft_papb(stack, take, 1);
		ft_sasb(take, 1);
		return (-1);
	}
	ft_rrarrb(stack, which);
	return (0);
}

size_t	find_biggy(t_data *stack, int which)
{
	size_t	position;
	size_t	res;
	size_t	stop;

	res = 0;
	stop = 0;
	position = 0;
	while (stack)
	{
		position++;
		if (stack->index > res)
		{
			stop = position;
			res = stack->index;
		}
		stack = stack->next;
	}
	if (which == 1)
		return (res);
	return (stop);
}
