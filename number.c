/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:57:18 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/27 18:17:39 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	how_much(t_data *stack, size_t padding)
{
	size_t	that_much;

	that_much = 0;
	while (stack)
	{
		if (stack->index < padding)
			that_much++;
		stack = stack->next;
	}
	return (that_much);
}
