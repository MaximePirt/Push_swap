/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 05:07:32 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/20 00:50:04 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tmp_loop(char **tmp, int tln, t_data *stack_a)
{
	int	j;
	int	len;

	j = 0;
	while (tmp[tln][j])
	{
		len = ft_checkplusminus(tmp[tln]);
		if (len == -1)
			ft_free_all(tmp, &stack_a);
		if (tmp[tln][j] == 35)
			continue ;
		if ((tmp[tln][j] < 48 || tmp[tln][j] > 57) && (tmp[tln][j] != 43
				&& tmp[tln][j] != 45))
			ft_free_all(tmp, &stack_a);
		j++;
	}
	return (1);
}

void	ft_conditions(t_data **stack_a, char **tmp, int tln, int i)
{
	int		len;
	long	j;

	(void)i;
	(void)*stack_a;
	len = ft_strlen(tmp[tln]);
	j = ft_atol(tmp[tln]);
	if ((len > 11 || !len) || (j > 2147483647 || j < -2147483648))
		ft_free_all(tmp, stack_a);
	len = tmp_loop(tmp, tln, *stack_a);
	if (i == 1 && tln == 0)
	{
		free(*stack_a);
		*stack_a = ft_datalstnew(j);
	}
	else if (!ft_check_doublon(*stack_a, (int)j))
		ft_datalstadd_back(stack_a, ft_datalstnew(j));
	else
		ft_free_all(tmp, stack_a);
	return ;
}
