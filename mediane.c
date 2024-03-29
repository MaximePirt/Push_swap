/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:03:50 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/29 21:11:26 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_padding(t_data *a)
{
	t_data	*tmp;
	size_t	res;

	tmp = NULL;
	ft_datalstcpy(a, &tmp);
	sort_the_copy(&tmp);
	indexation(&tmp, tmp);
	res = calcul_mediane(tmp);
	ft_free_all(NULL, &tmp, NULL, 0);
	return (res);
}

size_t	calcul_mediane(t_data *stack)
{
	size_t	res;

	res = ft_datalstsize(stack);
	if (res % 2 == 0)
		res = res / 2;
	else
		res = (res + 1) / 2;
	return (res);
}
