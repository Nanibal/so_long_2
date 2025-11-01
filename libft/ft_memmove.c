/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:56:41 by nayala            #+#    #+#             */
/*   Updated: 2025/04/08 13:12:55 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//move the content of a memory block to another
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if ((!dest && !src) || dest == src)
		return (dest);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d == s || d < s)
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += len;
		s += len;
		while (len--)
		{
			*--d = *--s;
		}
	}
	return (dest);
}
