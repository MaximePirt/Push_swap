/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:54:56 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/15 17:04:10 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int	ft_lstdupcheck(t_data *lst)
// {
// 	t_data	*cmp1;
// 	t_data	*lilcmp;
// 	t_data	*reset;
// 	int		x;

// 	x = 0;
// 	if (!lst)
// 		return (0);
// 	cmp1 = lst;
// 	reset = lst;
// 	lst = lst->next;
// 	reset = reset->next;
// 	while (cmp1)
// 	{
// 		lilcmp = cmp1;
// 		reset = reset->next;
// 		if (x == 1)
// 			lst = reset;
// 		x = 1;
// 		while (lst)
// 		{
// 			if (lilcmp->content == lst->content)
// 				return (0);
// 			lst = lst->next;
// 		}
// 		cmp1 = cmp1->next;
// 	}
// 	return (1);
// }

int	ft_check_doublon(t_data *lst, int valeur)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->number == valeur)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_data	*ft_datalstlast(t_data *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_datalstadd_back(t_data **lst, t_data *new)
{
	t_data	*tmp;

	if (!new || !lst)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		tmp = ft_datalstlast(*lst);
		tmp->next = new;
	}
}

t_data	*ft_datalstnew(int number)
{
	t_data	*new;

	new = 0;
	new = malloc(sizeof(t_data));
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

void	print_stack(t_data *stack)
{
	while (stack)
	{
		printf("%d\n", stack->number);
		stack = stack->next;
	}
}

// int	main(void)
// {
// 	int		i;
// 	int		z;
// 	t_data	*stack_a;

// 	i = 0;
// 	z = 10;
// 	stack_a = malloc(sizeof(t_data));
// 	if (!stack_a)
// 		return (0);
// 	while (i++ < 10)
// 		ft_datalstadd_back(&stack_a, ft_datalstnew(z++));
// 	if (!ft_check_doublon(stack_a, 113))
// 	{
// 		printf("oui je peux\n");
// 		ft_datalstadd_back(&stack_a, ft_datalstnew(113));
// 		print_stack(stack_a);
// 	}
// 	else
// 	{
// 		printf("non doublons");
// 		print_stack(stack_a);
// 	}
// 	return (0);
// }
