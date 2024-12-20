/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:21:40 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/30 16:21:42 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list *node;
	node = ft_lstnew("itttee?");
	if (!node)
	{
		printf("Errore: MALLOC");
		return (1);
	}
	printf("content: %s\n", (char *)node->content);
	printf("next: %p\n", (void *)node->next);
	free(node);
	return (0);
}
*/
