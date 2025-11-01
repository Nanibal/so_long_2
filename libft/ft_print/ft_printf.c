/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-22 08:18:43 by nayala            #+#    #+#             */
/*   Updated: 2025-04-22 08:18:43 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	printf_format(char const *format, va_list args)
{
	int				count;

	count = 0;
	if (*format == 'c')
		count += ft_print_char(va_arg(args, int));
	if (*format == 's')
		count += ft_print_str(va_arg(args, char *));
	if (*format == 'p')
		count += ft_print_ptr((unsigned long long)va_arg(args, void *));
	if (*format == 'd' || *format == 'i')
		count += ft_print_num(va_arg(args, int));
	if (*format == 'u')
		count += ft_print_base(va_arg(args, unsigned int), "0123456789");
	if (*format == 'x')
		count += ft_print_base(va_arg(args, unsigned int), "0123456789abcdef");
	if (*format == 'X')
		count += ft_print_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (*format == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
	{
		return (-1);
	}
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += printf_format(&format[++i], args);
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
