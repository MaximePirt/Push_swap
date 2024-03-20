/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:28:14 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/20 14:38:39 by mpierrot         ###   ########.fr       */
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
			ft_free_all(tmp, &a, NULL);
		while (tmp[tln])
		{
			ft_conditions(&a, tmp, tln, i);
			tln++;
		}
		free_tab(tmp);
		i++;
	}
	printf("\nstack a\n");
	print_stack(a);
	printf("\nstack b\n");
	print_stack(b);
	ft_move(&a, &b, "sa");
	ft_move(&a, &b, "pb");
	ft_move(&a, &b, "pb");
	ft_move(&a, &b, "sb");
	ft_move(&a, &b, "sa");
	ft_move(&a, &b, "rrb");
	ft_move(&a, &b, "ra");
	ft_move(&a, &b, "rb");
	ft_move(&a, &b, "rb");
	ft_move(&a, &b, "rr");
	ft_move(&a, &b, "pa");
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
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_parsing(argv, i);
	i++;
	return (0);
}
