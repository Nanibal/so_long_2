/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:19:02 by nayala            #+#    #+#             */
/*   Updated: 2025/04/09 10:01:37 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//search in a string for the last character specify
char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char) c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *) s);
	return ((char *) last);
}
