/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:21:50 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:21:51 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
#include <stdio.h>
int main(void)
{
	t_list *list;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew("nodo 1");
	node2 = ft_lstnew("nodo 2");
	node3 = ft_lstnew("nodo 3");
	if (!node1 || !node2 || !node3)
	{
		printf("Errore MALLOC");
		return (1);
	}
	list = NULL;
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node3);
	printf("Num di nodi: %d\n", ft_lstsize(list));
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/
