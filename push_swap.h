/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:45:47 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/29 21:23:07 by mpierrot         ###   ########.fr       */
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
	size_t			index;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

// main functions
void				ft_parsing(char **arg, int i);

// move functions
void				ft_move(t_data **a, t_data **b, char *movetodo);
void				ft_sasb(t_data **stack, int which);
void				ft_ss(t_data **a, t_data **b);
void				ft_papb(t_data **give, t_data **take, int which);
void				ft_rarb(t_data **stack, int which);
void				ft_rr(t_data **a, t_data **b);
void				ft_rrarrb(t_data **stack, int which);
void				ft_rrr(t_data **a, t_data **b);

////
void				swap_stack(t_data *lst, int which);
void				ft_datalstdelone(t_data *lst, int which);

// algorythm utils
void				butterfly_to_be(t_data **a, t_data **b);
void				find_index(t_data *a);
void				get_padding(t_data **a);
void				sorting_in_execution(t_data **stack_a, t_data **stack_b,
						size_t padding);
void				reput_in_a_at_end(t_data **stack_a, t_data **stack_b);

// Functions on the copy
void				sort_the_copy(t_data **stack);
void				indexation(t_data **id_stack, t_data *support);

// push_swap_utils
int					ft_count(char *tab, int valeur, int scdval);
int					ft_checkplusminus(char *str);
int					ft_check_doublon(t_data *lst, int valeur);
void				ft_free_all(char **tab, t_data **a, t_data **b, int i);
void				free_tab(char **tab);

// parsing_utils
int					tmp_loop(char **tmp, int tln, t_data *lst);
void				ft_conditions(t_data **lst, char **tmp, int tln, int i);
char				*noptozero(char *tmp);
char				*copy(char *tmp, size_t a, size_t i);

// lib funcs
long				ft_atol(const char *str);
int					ft_printf(const char *format, ...);

// lst functions
t_data				*ft_datalstlast(t_data *lst);
void				ft_datalstadd_back(t_data **lst, t_data *new);
void				ft_datalstadd_front(t_data **lst, t_data *new);
t_data				*ft_datalstnew(int number, size_t index);
void				ft_datalstclear(t_data **lst);
size_t				ft_datalstsize(t_data *lst);
void				ft_datalstcpy(t_data *give, t_data **copy);

// print_functions
void				ft_printab(char **tab);
void				print_stack(t_data *a);
void				print_index(t_data *stack);

// numbers functions
size_t				how_much(t_data *stack, size_t padding);
int					check_index(t_data *stack);
size_t				find_biggy(t_data *stack, int which);
size_t				find_minnie(t_data *stack, int which);
void				move_biggy_to(t_data **take, t_data **stack, int which);
void				move_minnie_to(t_data **take, t_data **stack, int which);

// Calculs functions
size_t				dataddition(t_data *a);
size_t				calcul_mediane(t_data *stack);
size_t				find_padding(t_data *a);

// small_list
void				two_num_sort(t_data **stack);
void				three_num_sort(t_data **stack);
void				five_four_num_sort(t_data **stack_a, t_data **stack_b,
						int which);

// Index
int					last_index(t_data **stack);
int					check_index(t_data *stack);

// Biggy and Minnie functions
int					move_biggy_r(t_data **take, t_data **stack, size_t biggy,
						int which);
int					move_biggy_rr(t_data **take, t_data **stack, size_t biggy,
						int which);

// pop && push
int					ft_pop(t_data **stack);
int					ft_pop_end(t_data **stack);
void				ft_push(t_data **stack, int value, size_t index);

#endif