/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 05:07:32 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/25 20:08:34 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tmp_loop(char **tmp, int tln, t_data *lst)
{
	int	j;
	int	len;

	j = 0;
	len = ft_checkplusminus(tmp[tln]);
	if (len == -1)
		ft_free_all(tmp, &lst, NULL, 1);
	while (tmp[tln][j])
	{
		if (tmp[tln][j] == 35)
			continue ;
		if ((tmp[tln][j] < 48 || tmp[tln][j] > 57) && (tmp[tln][j] != 43
				&& tmp[tln][j] != 45))
			ft_free_all(tmp, &lst, NULL, 1);
		j++;
	}
	return (1);
}

void	ft_conditions(t_data **lst, char **tmp, int tln, int i)
{
	int		len;
	long	j;

	tmp[tln] = noptozero(tmp[tln]);
	len = ft_strlen(tmp[tln]);
	j = ft_atol(tmp[tln]);
	if ((len > 11 || !len) && (j > 2147483647 || j < -2147483648))
		ft_free_all(tmp, lst, NULL, 1);
	if ((len > 11 || !len) || (j > 2147483647 || j < -2147483648))
		ft_free_all(tmp, lst, NULL, 1);
	len = tmp_loop(tmp, tln, *lst);
	if (i == 1 && tln == 0)
		*lst = ft_datalstnew(j);
	else if (!ft_check_doublon(*lst, (int)j))
		ft_datalstadd_back(lst, ft_datalstnew(j));
	else
		ft_free_all(tmp, lst, NULL, 1);
	return ;
}

char	*noptozero(char *tmp)
{
	size_t	i;
	size_t	a;
	size_t	len;

	len = ft_strlen(tmp);
	i = 0;
	a = 0;
	while (tmp[i] == '0')
		i++;
	if (!tmp[i])
	{
		i = 0;
		tmp[i] = '0';
		tmp[i + 1] = '\0';
		return (tmp);
	}
	while (tmp[i])
	{
		tmp[a] = tmp[i];
		a++;
		i++;
	}
	tmp[a] = '\0';
	return (tmp);
}
