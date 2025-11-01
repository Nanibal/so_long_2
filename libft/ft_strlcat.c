/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:03:14 by nayala            #+#    #+#             */
/*   Updated: 2025/04/08 11:05:25 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//joined to strings in a limited buffer
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = 0;
	s_len = 0;
	while (dest[d_len] && d_len < size)
		d_len++;
	while (src[s_len])
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	while ((d_len + i) < size -1 && src[i])
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
