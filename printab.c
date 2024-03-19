/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:55:20 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/20 00:50:48 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_printab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	printf("Given tab\n");
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return ;
}
