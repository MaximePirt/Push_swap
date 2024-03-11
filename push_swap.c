/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:05:35 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/11 20:36:14 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_parsing (char *arg)
{
	int	i;

	i = 0;
    if (!arg)
	{
		printf("TOOBAD\n");
        return (1);
	}
	while (arg[i])
	{
		
		if ((arg[i] < 48 || arg[i] > 57) && arg[i] != 32)
		{
			printf ("TOOBAD\n");
			return(1);
		}
		i++;
	}
	printf("ok\n");
    return (0);
}

int	main (int argc, char **argv)
{

	int	i;
	(void) argc;
	i = 1;
	if (!argv[i])
	printf ("No entry, tape something after the ./a.out please");
	while (argv[i])
	{
    	ft_parsing (argv[i]);
		i++;
	}
    return (0);
}