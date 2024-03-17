/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:45:47 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/17 06:46:59 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"

//////////////////////////
# include <stdio.h>
//////////////////////////

// structure
typedef struct s_data
{
	int				number;
	struct s_data	*next;
	struct s_data	*prev;
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

// push_swap_utils
int					ft_count(char *tab, int valeur, int scdval);
int					ft_checkplusminus(char *str);
int					ft_check_doublon(t_data *lst, int valeur);
void				ft_free_all(char **tab, t_data *arg1);
void				free_all(char **tab);

// parsing_utils
int					tmp_loop(char **tmp, int tln, t_data *stack_a);

// lib funcs
long				ft_atol(const char *str);
int					ft_printf(const char *format, ...);

// lst functions
t_data				*ft_datalstlast(t_data *lst);
void				ft_datalstadd_back(t_data **lst, t_data *new);
void				ft_datalstadd_front(t_data **lst, t_data *new);
t_data				*ft_datalstnew(int number);
void				ft_datalstclear(t_data **lst);

// print_functions
void				ft_printab(char **tab);
void				print_stack(t_data *stack);

#endif
