/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 10:35:01 by nayala            #+#    #+#             */
/*   Updated: 2025-04-11 10:35:01 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//divide a string by the parameter indicated
//free_split free the memory in case of an error in the array
static void	free_split(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}
//count the number of words that we have separated by the char value

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}
//create the new words and count the lengthof it

static char	*new_word(char const *s, char c, size_t *len)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	*len = i;
	return (ft_substr(s, 0, i));
}
//fills the array with the new words created by the char value

static int	fill_array(char **arr, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		arr[i] = new_word(s, c, &len);
		if (!arr[i])
		{
			free_split(arr, i);
			return (0);
		}
		s += len;
		i++;
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	if (!fill_array(arr, s, c, words))
		return (NULL);
	return (arr);
}
