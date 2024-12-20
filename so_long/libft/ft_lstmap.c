/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:21:32 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:21:33 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>
void *duplicate_content(void *content)
{
	char *str = (char *)content;
	return (ft_strdup(str));
}

void del_content(void *content)
{
	free(content);
}

int main(void)
{
	t_list *list;
	t_list *node1 = ft_lstnew(ft_strdup("NODO 1"));
	t_list *node2 = ft_lstnew(ft_strdup("NODO 2"));
	t_list *node3 = ft_lstnew(ft_strdup("NODO 3"));

	if (!node1 || !node2 || !node3)
	{
		printf("MALLUKNOW\n");
		return (1);
	}
	node1->next = node2;
	node2->next = node3;
	list = node1;

	t_list *new_list = ft_lstmap(list,duplicate_content,del_content);
	printf("lista originale\n");
	t_list *temp = list;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("NEW\n");
	temp = new_list;
	while (tempo)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;    
	}
	ft_lstclear(&list, del_content);
	ft_lstclear(&newlist, del_content);
	return (0);
}*/
