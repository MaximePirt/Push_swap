/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:45:47 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/15 17:28:10 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"

// structure
typedef struct s_data
{
	int				number;
	struct s_data	*next;
	// struct s_data	*back;
	/* data */
}					t_data;

// struct				tab2
// {
// 	int				ex;
// 	char			encoreex;
// 	struct s_data	encoreencore;
// 	/* data */
// };

// main functions
void				ft_parsing(char **arg);

// lib funcs
long				ft_atol(const char *str);

// lst functions
void				print_stack(t_data *stack);
int					ft_check_doublon(t_data *lst, int valeur);
t_data				*ft_datalstlast(t_data *lst);
void				ft_datalstadd_back(t_data **lst, t_data *new);
t_data	*ft_datalstnew(int number);

#endif
