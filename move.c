/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:42:21 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/20 13:51:57 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_data **a, t_data **b, char *movetodo)
{
	if (ft_strncmp(movetodo, "sa", 2) == 0)
		ft_sasb(a);
	else if (ft_strncmp(movetodo, "sb", 2) == 0)
		ft_sasb(b);
	else if (ft_strncmp(movetodo, "ss", 2) == 0)
		ft_ss(a, b);
	else if (ft_strncmp(movetodo, "pa", 2) == 0)
		ft_papb(b, a);
	else if (ft_strncmp(movetodo, "pb", 2) == 0)
		ft_papb(a, b);
	else if (ft_strncmp(movetodo, "rra", 3) == 0)
		ft_rrarrb(a);
	else if (ft_strncmp(movetodo, "rrb", 3) == 0)
		ft_rrarrb(b);
	else if (ft_strncmp(movetodo, "rrr", 3) == 0)
		ft_rrr(a, b);
	else if (ft_strncmp(movetodo, "ra", 2) == 0)
		ft_rarb(a);
	else if (ft_strncmp(movetodo, "rb", 2) == 0)
		ft_rarb(b);
	else if (ft_strncmp(movetodo, "rr", 2) == 0)
		ft_rr(a, b);
	else
		exit(EXIT_FAILURE);
	return ;
}
// sa
// sb
// ss
// pa
// pb
// ra
// rb
// rr
// rra
// rrb
// rrr