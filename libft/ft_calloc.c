/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 10:22:06 by nayala            #+#    #+#             */
/*   Updated: 2025-04-09 10:22:06 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//reserve a memory space and asigned value 0
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n_bytes;

	if (nmemb == 0 || size == 0)
	{
		n_bytes = 0;
		ptr = malloc(n_bytes);
	}
	else
	{
		n_bytes = nmemb * size;
		if (n_bytes / nmemb != size)
			return (NULL);
		ptr = malloc(n_bytes);
	}
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
