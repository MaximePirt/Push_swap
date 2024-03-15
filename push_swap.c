/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:28:14 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/15 18:16:59 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_parsing(char **arg)
{
	t_data	*stack_a;
	int		i;
	int		len;
	long	j;

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
		j = 0;
		if (len > 10)
		{
			printf("Wsh mon reuf ca depasse le INT_MAX la t as pas l'impression?");
			return ;
		}
		while (arg[i][j])
		{
			arg[i] = *ft_split(arg[i], 32);
			if ((arg[i][j] < 48 || arg[i][j] > 57) && arg[i][j] != 32)
			{
				printf("Un caractere n'etant pas un chiffre a ete inserer %c\n",
					arg[i][j]);
				return ;
			}
			// printf("ya une tite erreur la");
			j++;
		}
		// printf("capasse %s\n", arg[i]);
		if (!ft_check_doublon(stack_a, ft_atol(arg[i])))
		{
			ft_datalstadd_back(&stack_a, ft_datalstnew(ft_atol(arg[i])));
			// printf("ajouter");
		}
		else
		{
			printf("doublon");
			return ;
		}
		i++;
	}
	printf("\n\n\n Stack a : \n");
	print_stack(stack_a);
	printf("ok\n");
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
