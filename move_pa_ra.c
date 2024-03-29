/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pa_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:07:28 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/29 21:19:40 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(tmp);
	if (which == 3)
		return ;
}

void	ft_rr(t_data **a, t_data **b)
{
	ft_rarb(a, 3);
	ft_rarb(b, 3);
	ft_putstr_fd("rr\n", 1);
}
