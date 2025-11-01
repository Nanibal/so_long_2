/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pintf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-22 09:58:30 by nayala            #+#    #+#             */
/*   Updated: 2025-04-22 09:58:30 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
//Parte obligatoria
int		ft_print_base(unsigned long long nbr, char *base);
int		ft_print_num(int n);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_ptr(unsigned long long ptr);
size_t	ft_print_strlen(const char *str);
int		ft_printf(char const *format, ...);
#endif