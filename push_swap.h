/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:45:47 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/20 11:14:28 by mpierrot         ###   ########.fr       */
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
	int				value;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

// main functions
void				ft_parsing(char **arg, int i);

// move functions
void				ft_move(t_data **a, t_data **b, char *movetodo);
void				ft_sasb(t_data **stack);
void				ft_ss(t_data **a, t_data **b);
void				ft_papb(t_data **give, t_data **take);
void				ft_rarb(t_data **stack);
void				ft_rr(t_data **a, t_data **b);
void				ft_rrarrb(t_data **stack);
void				ft_rrr(t_data **a, t_data **b);

////
////
////
void				swap_stack(t_data *lst, int which);
void				ft_datalstdelone(t_data *lst, int which);

// push_swap_utils
int					ft_count(char *tab, int valeur, int scdval);
int					ft_checkplusminus(char *str);
int					ft_check_doublon(t_data *lst, int valeur);
void				ft_free_all(char **tab, t_data **a, t_data **b);
void				free_tab(char **tab);

// parsing_utils
int					tmp_loop(char **tmp, int tln, t_data *lst);
void				ft_conditions(t_data **lst, char **tmp, int tln, int i);
char				*noptozero(char *tmp);

// lib funcs
long				ft_atol(const char *str);
int					ft_printf(const char *format, ...);

// lst functions
t_data				*ft_datalstlast(t_data *lst);
void				ft_datalstadd_back(t_data **lst, t_data *new);
void				ft_datalstadd_front(t_data **lst, t_data *new);
t_data				*ft_datalstnew(int number);
void				ft_datalstclear(t_data **lst);
int					ft_datalstsize(t_data *lst);
// print_functions
void				ft_printab(char **tab);
void				print_stack(t_data *a);

int					ft_pop(t_data **stack);
void				ft_push(t_data **stack, int value);
#endif