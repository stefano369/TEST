/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:34 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:20:35 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int main(void)
{
	t_list *list;
	t_list *node1;
	t_list *node2;

	node1 = ft_lstnew("nodo1");
	node2 = ft_lstnew("nodo2");
	if (!node1 || !node2)
	{
		printf("Errore MALLOC");
		return (1);
	}
	list = NULL;
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	printf("primo nodo: %s\n", (char *)list->content);
	printf("secondo nodo: %s\n", (char *)list->next->content);
	free(node1);
	free(node2);
	return (0);
}*/
