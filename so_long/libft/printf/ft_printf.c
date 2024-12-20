/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:45:49 by smurgia           #+#    #+#             */
/*   Updated: 2024/12/02 16:45:51 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_support(const char *format, va_list *args, int *count)
{
	if (*format == '%')
		(*count) += ft_putchar('%');
	if (*format == 'c')
		(*count) += ft_putchar(va_arg(*args, int));
	if (*format == 's')
		(*count) += ft_putstr(va_arg(*args, char *));
	if (*format == 'd' || *format == 'i')
		(*count) += ft_putnbr(va_arg(*args, int));
	if (*format == 'u')
		(*count) += ft_putnbr_nosign(va_arg(*args, unsigned int));
	if (*format == 'x')
		(*count) += ft_puthex(va_arg(*args, unsigned int), 0);
	if (*format == 'X')
		(*count) += ft_puthex(va_arg(*args, unsigned int), 1);
	if (*format == 'p')
		(*count) += ft_putptr(va_arg(*args, void *));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			ft_support(format, &args, &count);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
