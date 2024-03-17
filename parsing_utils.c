/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 05:07:32 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/17 06:47:12 by mpierrot         ###   ########.fr       */
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
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_all(tmp, stack_a);
			return (-1);
		}
		if (tmp[tln][j] == 35)
			continue ;
		if ((tmp[tln][j] < 48 || tmp[tln][j] > 57) && (tmp[tln][j] != 43
				&& tmp[tln][j] != 45))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_all(tmp, stack_a);
			return (-1);
		}
		j++;
	}
	return (1);
}

// int	tmp_loop(char **tmp, int tln, int len, t_data *stack_a)
// {
// 	int	j;

// 	j = 0;
// 	while (tmp[tln][j])
// 	{
// 		len = ft_checkplusminus(tmp[tln]);
// 		if (len == -1)
// 		{
// 			ft_putstr_fd("Error\n", 2);
// 			ft_datalstclear(&stack_a);
// 			free(stack_a);
// 			free_all(tmp);
// 			return (-1);
// 		}
// 		if (tmp[tln][j] == 35)
// 			continue ;
// 		if ((tmp[tln][j] < 48 || tmp[tln][j] > 57) && (tmp[tln][j] != 43
// 				&& tmp[tln][j] != 45))
// 		{
// 			ft_putstr_fd("Error\n", 2);
// 			ft_datalstclear(&stack_a);
// 			free(stack_a);
// 			free_all(tmp);
// 			return (-1);
// 		}
// 		j++;
// 	}
// 	return (1);
// }
