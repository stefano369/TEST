/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:51:11 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/20 16:51:14 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*p;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	if (total_size / nmemb != size)
		return (NULL);
	p = malloc(total_size);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, total_size);
	return (p);
}
