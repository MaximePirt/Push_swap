/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:28:14 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/17 08:37:35 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing(char **arg)
{
	t_data	*stack_a;
	char	**tmp;
	int		i;
	long	len;
	long	j;
	long	tln;
	int		protec;

	stack_a = NULL;
	i = 1;
	if (!arg[i])
		return ;
	stack_a = malloc(sizeof(t_data));
	if (!stack_a)
	{
		ft_datalstclear(&stack_a);
		free(stack_a);
		return ;
	}
	len = 0;
	while (arg[i])
	{
		tln = 0;
		tmp = ft_split(arg[i], 32);
		if (!tmp[tln])
		{
			ft_putstr_fd("Error\n", 2);
			ft_datalstclear(&stack_a);
			free(stack_a);
			free_all(tmp);
			return ;
		}
		while (tmp[tln])
		{
			len = ft_strlen(tmp[tln]);
			j = ft_atol(tmp[tln]);
			if ((len > 11 || !len) && (j > 2147483647 || j < -2147483648))
			{
				ft_putstr_fd("Error\n", 2);
				ft_datalstclear(&stack_a);
				free(stack_a);
				free_all(tmp);
				return ;
			}
			j = 0;
			protec = tmp_loop(tmp, tln, stack_a);
			if (protec == -1)
			{
				ft_putstr_fd("Error\n", 2);
				return ;
			}
			len = ft_atol(tmp[tln]);
			if (len > 2147483647 || len < -2147483648)
			{
				ft_putstr_fd("Error\n", 2);
				ft_datalstclear(&stack_a);
				free(stack_a);
				free_all(tmp);
				return ;
			}
			if (i == 1 && tln == 0)
			{
				free(stack_a);
				stack_a = ft_datalstnew(ft_atol(tmp[tln]));
			}
			else if (!ft_check_doublon(stack_a, (int)len))
				ft_datalstadd_back(&stack_a, ft_datalstnew(ft_atol(tmp[tln])));
			else
			{
				ft_putstr_fd("Error\n", 2);
				ft_datalstclear(&stack_a);
				free(stack_a);
				free_all(tmp);
				return ;
			}
			tln++;
		}
		free_all(tmp);
		i++;
	}
	printf("\n\n\nStack a : \n");
	print_stack(stack_a);
	ft_datalstclear(&stack_a);
	free(stack_a);
	return ;
}

int	main(int argc, char **argv)
{
	int	i;

	(void)argc;
	i = 1;
	if (!argv[i])
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_parsing(argv);
	i++;
	return (0);
}
