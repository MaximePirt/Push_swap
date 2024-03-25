/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:18:27 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/25 20:34:40 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_to_be(t_data **a, t_data **b)
{
	int	jz;

	// int	jz;
	// jz = 50;
	(void)**b;
	jz = 20;
	find_padding(*a);
	sorting_in_execution(a, b, jz);
}

void	find_padding(t_data *a)
{
	t_data	*tmp_a;

	tmp_a = NULL;
	ft_datalstcpy(a, &tmp_a);
	sort_the_copy(&tmp_a);
	indexation(&a, tmp_a);
	ft_free_all(NULL, &tmp_a, NULL, 0);
	ft_printf("\n Voila mon indexation : \n");
	print_index(a);
}

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

void	sort_the_copy(t_data **stack)
{
	t_data	*start;
	t_data	*check;
	int		swap;

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

void	ft_datalstcpy(t_data *give, t_data **copy)
{
	*copy = NULL;
	while (give != NULL)
	{
		ft_datalstadd_back(copy, ft_datalstnew(give->value));
		give = give->next;
	}
}

void	padding_fly(t_data **a)
{
	size_t	i;

	i = ft_datalstsize(*a);
	if (i < 30)
		return ;
}

void	sorting_in_execution(t_data **stack_a, t_data **stack_b, int padding)
{
	size_t	i;
	t_data	*start;
	t_data	*cursor;

	(void)padding;
	start = *stack_a;
	i = 1;
	// while (start)
	// {
	cursor = start;
	printf("Voila les index");
	print_index(cursor);
	while (cursor->next)
	{
		printf("\nVoici l'indexe du curseur [%zu]\n", cursor->index);
		printf("\nVoici l'indexe recherhce[%zu]\n", i);
		while (cursor->index != i)
		{
			ft_rarb(&cursor, 1);
		}
		i++;
		ft_papb(&cursor, stack_b, 2);
	}
	// 	start = start->next;
	// }
	// reput_in_a_at_end(stack_a, stack_b, padding);
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
