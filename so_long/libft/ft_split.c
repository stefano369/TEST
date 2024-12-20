/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:24:59 by smurgia           #+#    #+#             */
/*   Updated: 2024/11/23 16:25:00 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	handle_word(const char **s, char c, char **result, int i)
{
	int		len;
	int		j;
	char	*word;

	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (0);
	j = 0;
	while (j < len)
	{
		word[j] = (*s)[j];
		j++;
	}
	word[j] = '\0';
	result[i] = word;
	*s += len;
	return (1);
}

static char	**initialize_split(const char *s, char c, int *words)
{
	char	**result;

	if (!s)
		return (NULL);
	*words = count_words(s, c);
	result = (char **)malloc((*words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;
	int		i;

	result = initialize_split(s, c, &words);
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!handle_word(&s, c, result, i++))
			{
				free_split(result, i - 1);
				return (NULL);
			}
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	int i = 0;
	char *str = "\0\0\0aaaa\0bbb\0";
	char dst = '\0';
	char **result = ft_split(str, dst);
	while (result[i] != NULL)
	{
		printf("%s\n",result[i]);
		i++;
	}
}*/