/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:12:34 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/22 19:16:17 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char *tab, int valeur, int scdval)
{
	int	count;
	int	i;

	i = 0;
	if (!valeur)
		valeur = scdval;
	if (!scdval)
		scdval = valeur;
	if (!tab || (!valeur && !scdval))
		return (-1);
	count = 0;
	while (tab[i])
	{
		if (tab[i] == valeur || tab[i] == scdval)
		{
			count++;
			if (count >= 2)
				return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_checkplusminus(char *str)
{
	int	i;

	i = ft_count(str, 43, 45);
	if (i == -1)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == 43 || str[i] == 45)
		{
			if (i > 0 && (str[i - 1] > 47 && str[i - 1] < 58))
				return (-1);
			else
			{
				i++;
				if (str[i] == 32 || !str[i])
					return (-1);
			}
		}
		i++;
	}
	return (1);
}

// int	ft_checkplusminus(char *str)
// {
// 	int	i;

// 	i = ft_count(str, 43, 45);
// 	if (i == -1)
// 		return (-1);
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 43 || str[i] == 45)
// 		{
// 			i--;
// 			if (i < 0 && (str[i] > 47 && str[i] < 58))
// 				return (-1);
// 			i = i + 2;
// 			if (str[i] == 32 || !str[i])
// 				return (-1);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	ft_check_doublon(t_data *lst, int valeur)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->value == valeur)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_free_all(char **tab, t_data **a, t_data **b)
{
	if (tab && a)
		ft_putstr_fd("Error\n", 2);
	if (tab)
	{
		free_tab(tab);
		tab = NULL;
	}
	if (a)
	{
		ft_datalstclear(a);
		a = NULL;
	}
	if (b)
	{
		ft_datalstclear(b);
		b = NULL;
	}
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
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
	tab = NULL;
	return ;
}
