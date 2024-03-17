/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:12:34 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/17 07:03:08 by mpierrot         ###   ########.fr       */
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
	while (tab[i])
	{
		count = 0;
		if (tab[i] == valeur || tab[i] == scdval)
		{
			count++;
			i++;
			while (tab[i] == 32)
				i++;
			if (tab[i] == valeur || tab[i] == scdval)
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
	{
		return (-1);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == 43 || str[i] == 45)
		{
			i--;
			if ((str[i] > 47 && str[i] < 58) && i > -1)
				return (-1);
			i = i + 2;
			if (str[i] == 32 || !str[i])
				return (-1);
		}
		i++;
	}
	return (1);
}

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

void	ft_free_all(char **tab, t_data *arg1)
{
	if (!tab && !arg1)
		return ;
	if (tab)
	{
		free(*tab);
		*tab = NULL;
	}
	if (arg1)
	{
		ft_datalstclear(&arg1);
		free(arg1);
		arg1 = NULL;
	}
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
	tab = NULL;
}
