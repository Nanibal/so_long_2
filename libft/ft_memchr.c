/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:02:27 by nayala            #+#    #+#             */
/*   Updated: 2025/04/09 10:28:02 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//search for a specify value in a memory block
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *) s;
	while (n > 0)
	{
		if (*ptr == (unsigned char) c)
			return ((void *) ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
