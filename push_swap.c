/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:28:14 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/16 18:38:06 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_datalstclear(t_data **lst)
{
	t_data	*tmp;
	t_data	*next;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		tmp->number = 0;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	free_all(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

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
		tln = 0;
		tmp = ft_split(arg[i], 32);
		while (tmp[tln])
		{
			len = ft_strlen(tmp[tln]);
			if (len > 10 || !len)
				return ;
			j = 0;
			while (tmp[tln][j])
			{
				if (tmp[tln][j] < 48 || tmp[tln][j] > 57)
				{
					printf("\nChar instead of an int : %c\n", tmp[tln][j]);
					ft_datalstclear(&stack_a);
					free(stack_a);
					free_all(tmp);
					return ;
				}
				j++;
			}
			len = ft_atol(tmp[tln]);
			if (len > 2147483647)
			{
				printf("Bigger than INT_MAX, calm down please");
				return ;
			}
			if (!ft_check_doublon(stack_a, len))
				ft_datalstadd_back(&stack_a, ft_datalstnew(ft_atol(tmp[tln])));
			else
			{
				printf("You put twice the same arg");
				ft_datalstclear(&stack_a);
				return ;
			}
			tln++;
		}
		ft_printab(tmp);
		free_all(tmp);
		i++;
	}
	printf("\n\n\nStack a : \n");
	print_stack(stack_a);
	ft_datalstclear(&stack_a);
	// free(stack_a);
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
