/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:21:15 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:21:16 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void del_content(void *content)
{
	free(content);
}

#include <stdio.h>
int main(void)
{
	t_list *node = ft_lstnew(ft_strdup("test node"));
	if (!node)
	{
		printf("errorrrrrr MALLLLLLLLLOCCCKCKKCKCKCKCK");
		return (1);
	}
	printf("prima %s\n", (char *)node->content);
	ft_lstdelone(node, del_content);
	printf("dopppppu\n");
	return (0);
}*/
