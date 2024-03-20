/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:07:28 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/20 14:15:35 by mpierrot         ###   ########.fr       */
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

void	ft_push(t_data **stack, int value)
{
	ft_datalstadd_front(stack, ft_datalstnew(value));
}

void	ft_papb(t_data **give, t_data **take)
{
	int		value;
	size_t	len;

	len = ft_datalstsize(*give);
	if (len > 0)
	{
		value = ft_pop(give);
		ft_push(take, value);
	}
}

void	ft_rarb(t_data **stack)
{
	size_t	len;
	size_t	counter;
	int		value;

	counter = 0;
	len = ft_datalstsize(*stack);
	while (counter < len - 1)
	{
		value = ft_pop_end(stack);
		ft_push(stack, value);
		counter++;
	}
}

void	ft_rr(t_data **a, t_data **b)
{
	size_t	len;
	size_t	counter;
	int		value;

	counter = 0;
	len = ft_datalstsize(*a);
	while (counter < len - 1)
	{
		value = ft_pop_end(a);
		ft_push(a, value);
		counter++;
	}
	counter = 0;
	len = ft_datalstsize(*b);
	while (counter < len - 1)
	{
		value = ft_pop_end(b);
		ft_push(b, value);
		counter++;
	}
}

void	ft_rrr(t_data **a, t_data **b)
{
	size_t	len;
	size_t	counter;
	int		value;

	counter = 0;
	len = ft_datalstsize(*a);
	while (counter < len - 1)
	{
		value = ft_pop(a);
		ft_datalstadd_back(a, ft_datalstnew(value));
		counter++;
	}
	counter = 0;
	len = ft_datalstsize(*b);
	while (counter < len - 1)
	{
		value = ft_pop(b);
		ft_datalstadd_back(b, ft_datalstnew(value));
		counter++;
	}
}

void	ft_rrarrb(t_data **stack)
{
	size_t	len;
	size_t	counter;
	int		value;

	counter = 0;
	len = ft_datalstsize(*stack);
	while (counter < len - 1)
	{
		value = ft_pop(stack);
		ft_datalstadd_back(stack, ft_datalstnew(value));
		counter++;
	}
}

int	ft_datalstsize(t_data *lst)
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

void	ft_sasb(t_data **stack)
{
	int	value;
	int	value2;
	int	len;

	len = ft_datalstsize(*stack);
	if (len > 2)
	{
		value = ft_pop(stack);
		value2 = ft_pop(stack);
		ft_push(stack, value);
		ft_push(stack, value2);
	}
}

void	ft_ss(t_data **a, t_data **b)
{
	int	value;
	int	value2;
	int	len;

	len = ft_datalstsize(*a);
	if (len > 2)
	{
		value = ft_pop(a);
		value2 = ft_pop(a);
		ft_push(a, value);
		ft_push(a, value2);
	}
	len = ft_datalstsize(*b);
	if (len > 2)
	{
		value = ft_pop(b);
		value2 = ft_pop(b);
		ft_push(b, value);
		ft_push(b, value2);
	}
}
