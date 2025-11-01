/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-22 09:34:48 by nayala            #+#    #+#             */
/*   Updated: 2025-04-22 09:34:48 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_print_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	ft_print_base(unsigned long long nbr, char *base)
{
	int	base_len;
	int	count;

	base_len = ft_print_strlen(base);
	count = 0;
	if (nbr >= (unsigned long long)base_len)
		count += ft_print_base(nbr / base_len, base);
	count += write(1, &base[nbr % base_len], 1);
	return (count);
}
