/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:19 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:20:22 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
/*
#include <stdio.h>
int main(void)
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("nodo 1");
	t_list *node2 = ft_lstnew("nodo 2");
	t_list *node3 = ft_lstnew("nodo 3");

	if (!node1 || !node2 || !node3)
}*/
