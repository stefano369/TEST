/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:47 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:20:55 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void print_cosasa(void *content)
{
	printf("%s\n", (char *)content);
}

#include <stdio.h>
int main(void)
{
	t_list *node1 = ft_lstnew(ft_strudup("node1"))
	t_list *node2 = ft_lstnew(ft_strdup("node2"));
	t_list *node3 = ft_lstnew(ft_strdup("node3"));
	if (!node1 || !node2 || !node3)
	{
		printf("did shit with malloc mate!");
		return (1);
	}
	node1->next = node2;
	node2->next = node3;

	printf("Contenuto lista");
	ft_lstiter(node1, print_content);

	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/
