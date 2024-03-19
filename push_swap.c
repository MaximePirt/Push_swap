/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:28:14 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/20 00:42:18 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing(char **arg, int i)
{
	t_data	*stack_a;
	char	**tmp;
	long	tln;

	if (!arg[i])
		return ;
	stack_a = ft_calloc(1, sizeof(t_data));
	if (!stack_a)
		ft_free_all(0, &stack_a);
	while (arg[i])
	{
		tln = 0;
		tmp = ft_split(arg[i], 32);
		if (!tmp[tln])
			ft_free_all(tmp, &stack_a);
		while (tmp[tln])
		{
			ft_conditions(&stack_a, tmp, tln, i);
			tln++;
		}
		free_tab(tmp);
		i++;
	}
	print_stack(stack_a);
	ft_free_all(NULL, &stack_a);
}

int	main(int argc, char **argv)
{
	int	i;

	(void)argc;
	i = 1;
	if (!argv[i])
	{
		ft_putstr_fd("Error la\n", 2);
		return (1);
	}
	ft_parsing(argv, i);
	i++;
	return (0);
}
