/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:28:14 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/29 21:24:39 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing(char **arg, int i)
{
	t_data	*a;
	t_data	*b;
	char	**tmp;
	long	tln;

	if (!arg[i])
		return ;
	b = NULL;
	a = NULL;
	while (arg[i])
	{
		tln = 0;
		tmp = ft_split(arg[i], 32);
		if (!tmp[tln])
			ft_free_all(tmp, &a, NULL, 1);
		while (tmp[tln])
		{
			ft_conditions(&a, tmp, tln, i);
			tln++;
		}
		free_tab(tmp);
		i++;
	}
	butterfly_to_be(&a, &b);
	ft_free_all(NULL, &a, &b, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (1);
	ft_parsing(argv, i);
	i++;
	return (0);
}
