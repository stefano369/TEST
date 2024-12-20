/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:46:10 by smurgia           #+#    #+#             */
/*   Updated: 2024/12/02 16:46:12 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long n, int is_upper)
{
	int		count;
	char	*hexdig_lower;
	char	*hexdig_upper;

	count = 0;
	hexdig_lower = "0123456789abcdef";
	hexdig_upper = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_puthex(n / 16, is_upper);
	}
	if (is_upper)
	{
		count += ft_putchar(hexdig_upper[n % 16]);
	}
	else
	{
		count += ft_putchar(hexdig_lower[n % 16]);
	}
	return (count);
}
