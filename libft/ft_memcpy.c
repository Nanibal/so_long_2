/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:14:19 by nayala            #+#    #+#             */
/*   Updated: 2025/04/08 12:28:54 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//copy the memory content from a source to a destiny
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;	

	if ((!dest && !src) || dest == src)
		return (dest);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
