/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:54:56 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/25 19:42:12 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_data *stack)
{
	t_data	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("[%d]\n", tmp->value);
		tmp = tmp->next;
	}
}

void	print_index(t_data *stack)
{
	t_data	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("[%ld]\n", tmp->index);
		tmp = tmp->next;
	}
}
