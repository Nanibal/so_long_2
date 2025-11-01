/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:49:28 by nayala            #+#    #+#             */
/*   Updated: 2025-04-24 07:49:28 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
//Parte obligatoria
char	*get_next_line(int fd);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_strdup(const char *s);
size_t	ft_gnl_strlen(const char *str);
#endif