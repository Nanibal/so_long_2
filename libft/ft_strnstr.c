/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:30:52 by nayala            #+#    #+#             */
/*   Updated: 2025/04/09 10:39:21 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//search for a substring in a string and return that direction
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
	{
		return ((char *) big);
	}
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j]
			&& big[i + j] == little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
