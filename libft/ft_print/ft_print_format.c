/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 09:08:27 by nayala            #+#    #+#             */
/*   Updated: 2025-04-23 09:08:27 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = ft_print_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	count += ft_print_base(ptr, "0123456789abcdef");
	return (count);
}

int	ft_print_num(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	count += ft_print_base(nb, "0123456789");
	return (count);
}
