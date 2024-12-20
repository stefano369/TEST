/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:19:13 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/19 19:19:14 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last_i;

	i = 0;
	last_i = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_i = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	if (last_i != -1)
		return ((char *)&s[last_i]);
	return (NULL);
}
