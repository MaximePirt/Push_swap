/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:07:28 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/28 20:28:54 by mpierrot         ###   ########.fr       */
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

void	ft_push(t_data **stack, int value, size_t index)
{
	ft_datalstadd_front(stack, ft_datalstnew(value, index));
}

void	ft_papb(t_data **give, t_data **take, int which)
{
	int		value;
	size_t	len;
	size_t	index;

	len = ft_datalstsize(*give);
	if (len)
	{
		index = (*give)->index;
		value = ft_pop(give);
		ft_push(take, value, index);
	}
	if (which == 1)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	ft_rarb(t_data **stack, int which)
{
	t_data	*tmp;
	size_t	len;
	size_t	counter;
	size_t	index;
	int		value;

	counter = 0;
	len = ft_datalstsize(*stack);
	// if (len < 2)
	// 	return ;
	tmp = NULL;
	ft_datalstcpy(*stack, &tmp);
	while (counter < len - 1)
	{
		index = last_index(&tmp);
		value = ft_pop_end(stack);
		ft_push(stack, value, index);
		counter++;
	}
	if (which == 1)
		ft_putstr_fd("ra\n", 1);
	else if (which == 2)
		ft_putstr_fd("rb\n", 1);
	if (which == 3)
		return ;
}

void	ft_rr(t_data **a, t_data **b)
{
	ft_rarb(a, 3);
	ft_rarb(b, 3);
	ft_putstr_fd("rr\n", 1);
}

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

size_t	ft_datalstsize(t_data *lst)
{
	size_t	i;
	t_data	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// void	ft_rarb(t_data **stack)
// {
// 	t_data	*tmp;
// 	int		value;
// 	int		value2;

// 	tmp = *stack;
// 	while (tmp && tmp->next)
// 		tmp = tmp->next;
// 	value = ft_pop(stack);
// 	value2 = ft_pop_end(stack);
// 	ft_push(stack, value2);
// 	ft_datalstadd_back(stack, ft_datalstnew(value));
// }

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
