/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 11:20:49 by nayala            #+#    #+#             */
/*   Updated: 2025-04-09 11:20:49 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//extract a substring form a string indicateing the start and size
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*sub_s;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_s = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (i < len)
		sub_s[i++] = s[start++];
	sub_s[i] = '\0';
	return (sub_s);
}
