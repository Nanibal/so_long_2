/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:52:52 by nayala            #+#    #+#             */
/*   Updated: 2025-04-24 07:52:52 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//calculated the size of a string
size_t	ft_gnl_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (0);
	while (str && str[length] != '\0')
	{
		length++;
	}
	return (length);
}

//duplicate a string to a memory space
char	*ft_gnl_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_gnl_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

//extract a substring form a string indicateing the start and size
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*sub_s;

	if (!s)
		return (NULL);
	s_len = ft_gnl_strlen(s);
	if (start >= s_len)
		return (ft_gnl_strdup(""));
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

//merge two strings
char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_gnl_strdup(s2));
	if (!s2)
		return (ft_gnl_strdup(s1));
	ptr = (char *) malloc(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

//search in a string for the first indicated character
char	*ft_gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *) s);
	return (NULL);
}
