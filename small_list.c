/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:00:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/27 20:39:56 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_num_sort(t_data **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		ft_sasb(stack, 1);
}

void	five_four_num_sort(t_data **stack_a, t_data **stack_b, int which)
{
	if (which == 5)
		move_minnie_to(stack_b, stack_a, 1);
	move_minnie_to(stack_b, stack_a, 1);
	three_num_sort(stack_a);
	ft_papb(stack_b, stack_a, 1);
	if (which == 5)
		ft_papb(stack_b, stack_a, 1);
}

void	move_biggy_to(t_data **take, t_data **stack, int which)
{
	size_t	biggy_position;
	size_t	biggy;
	size_t	len;

	biggy = find_biggy(*stack, 1);
	biggy_position = find_biggy(*stack, 2);
	len = ft_datalstsize(*stack);
	if (biggy_position <= (len / 2))
	{
		while ((*stack)->index != biggy)
			ft_rarb(stack, which);
	}
	else
		while ((*stack)->index != biggy)
			ft_rrarrb(stack, which);
	if (which == 1)
		ft_papb(stack, take, 2);
	else
		ft_papb(stack, take, 1);
}

void	move_minnie_to(t_data **take, t_data **stack, int which)
{
	size_t	minnie_position;
	size_t	minnie;
	size_t	len;

	minnie = find_minnie(*stack, 1);
	minnie_position = find_biggy(*stack, 2);
	len = ft_datalstsize(*stack);
	if (minnie_position <= (len / 2))
	{
		while ((*stack)->index != minnie)
			ft_rarb(stack, which);
	}
	else
		while ((*stack)->index != minnie)
			ft_rrarrb(stack, which);
	if (which == 1)
		ft_papb(stack, take, 2);
	else
		ft_papb(stack, take, 1);
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

size_t	find_minnie(t_data *stack, int which)
{
	size_t	position;
	size_t	res;
	size_t	stop;

	res = stack->index;
	position = 0;
	stop = 0;
	while (stack)
	{
		position++;
		if (stack->index < res)
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

void	three_num_sort(t_data **stack)
{
	int		i;
	t_data	*t;

	t = *stack;
	i = check_index(*stack);
	if (i == 0)
		return ;
	if ((t->index > t->next->index && t->next->index < t->next->next->index
			&& t->next->next->index > t->index) || (t->index > t->next->index
			&& t->next->index > t->next->next->index
			&& t->next->next->index < t->index) || (t->index < t->next->index
			&& t->next->index > t->next->next->index
			&& t->next->next->index > t->index))
		ft_sasb(stack, 1);
	if (t->index > t->next->index && t->next->index < t->next->next->index
		&& t->next->next->index < t->index)
		ft_rarb(stack, 1);
	else if ((t->index < t->next->index && t->next->index > t->next->next->index
			&& t->next->next->index < t->index))
		ft_rrarrb(stack, 1);
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

// void	five_num_sort(t_data **stack_a, t_data **stack_b)
// {
// }