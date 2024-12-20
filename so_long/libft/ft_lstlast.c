/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:21:24 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:21:25 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
int main(void)
{
	t_list *node1 = ft_lstnew("nodo1");
	t_list *node2 = ft_lstnew("nodo2");
	t_list *node3 = ft_lstnew("nodo3");    

	if (!node1 || !node2 || !node3)
	{
		printf("Malloc error!");
		return (1);
	}
	node1->next = node2;
	node2->next = node3;
	t_list *last = ft_lstlast(node1);
	if (last)
		printf("LAST NODE: %s\n", (char *)last->content);
	else
		printf("empty");
	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/
