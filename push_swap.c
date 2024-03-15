/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:28:14 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/15 19:16:43 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_parsing(char **arg)
{
	t_data	*stack_a;
	char	**tmp;
	int		i;
	long	len;
	long	j;
	long	tln;

	stack_a = malloc(sizeof(t_data));
	if (!stack_a)
		return ;
	len = 0;
	i = 1;
	if (!arg[i])
		return ;
	while (arg[i])
	{
		len = ft_strlen(arg[i]);
		if (len > 10)
			return ;
		tmp = ft_split(arg[i], ' ');
		ft_printab(tmp);
		tln = 0;
		while (tmp[tln])
		{
			j = 1;
			while (tmp[tln][j])
			{
				if (tmp[tln][j] < 48 || tmp[tln][j] > 57)
				{
					printf("char hors chiffre %c\n", tmp[i][j]);
					free(stack_a);
					free(tmp);
					return ;
				}
				j++;
			}
			len = ft_atol(tmp[tln]);
			if (!ft_check_doublon(stack_a, len))
			{
				if (len > 2147483647)
				{
					printf("troplong");
					return ;
				}
				ft_datalstadd_back(&stack_a, ft_datalstnew(ft_atol(tmp[tln])));
			}
			else
			{
				printf("doublon");
				free(stack_a);
				return ;
			}
			tln++;
		}
		free(tmp);
		i++;
	}
	printf("\n\n\nStack a : \n");
	print_stack(stack_a);
	printf("ok\n");
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
		printf("No entry, tape something after the ./push_swap please");
		return (1);
	}
	ft_parsing(argv);
	i++;
	return (0);
}
