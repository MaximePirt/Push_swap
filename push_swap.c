/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:28:14 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/23 06:52:52 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing(char **arg, int i)
{
	t_data	*a;
	t_data	*b;
	char	**tmp;
	long	tln;
	int		jz;

	if (!arg[i])
		return ;
	b = NULL;
	a = NULL;
	while (arg[i])
	{
		tln = 0;
		tmp = ft_split(arg[i], 32);
		if (!tmp[tln])
			ft_free_all(tmp, &a, NULL);
		while (tmp[tln])
		{
			ft_conditions(&a, tmp, tln, i);
			tln++;
		}
		free_tab(tmp);
		i++;
	}
	// ft_printf("\nstack a\n");
	// print_stack(a);
	jz = 50;
	sorting_in_execution(&a, &b, jz);
	// ft_printf("\nAfter sorting\n");
	printf("\nstack a\n");
	print_stack(a);
	printf("\nstack b\n");
	print_stack(b);
	ft_free_all(NULL, &a, &b);
}
#include "limits.h"

int	main(int argc, char **argv)
{
	int	i;

	// printf("%ld", LONG_MAX);
	(void)argc;
	i = 1;
	if (!argv[i])
		return (1);
	ft_parsing(argv, i);
	i++;
	return (0);
}
