/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:54:56 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/17 09:09:04 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_data *stack)
{
	printf("\n\n\nStack a : \n");
	while (stack)
	{
		printf("    %d\n", stack->number);
		stack = stack->next;
	}
	printf("----------\n    a\n");
}