/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:21:56 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/14 22:21:36 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newNode;

	newNode = 0;
	newNode = malloc(sizeof(t_list) * 1);
	if (newNode == NULL)
		return (NULL);
	newNode->content = content;
	newNode->next = NULL;
	return (newNode);
}

// int	main(void)
// {
// 	char *p = "Salut";
// 	t_list *res;
// 	res = ft_lstnew(p);
// 	p = "wsh";
// 	res = ft_lstnew(p);
// 	p = "lereuf";
// 	res = ft_lstnew(p);
// 	p = "coucou";
// 	res = ft_lstnew(p);

// 	printf("%s", res->content);
// 	return (0);
// }