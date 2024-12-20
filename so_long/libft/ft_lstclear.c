/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:21:05 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:21:07 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
void del_content(void *content)
{
	free(content);
}

int main(void)
{
	t_list *list;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	if (!node1 || !node2 || !node3)
	{
		printf("MALLLLOC :(");
		return (1);
	}
	node1->next = node2;
	node2->next = node3;
	list =node1;

	prtinf("prima bitchhh");
	t_list *temp = list;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&list, del_content);
	if (!list)
		printf("GOOOOOOOD GOOD.");
	else
		printf("ERRRRRORRRRRRR");
	return (0);
}*/
