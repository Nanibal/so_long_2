/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-10 11:39:33 by nayala            #+#    #+#             */
/*   Updated: 2025-04-10 11:39:33 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//print a character in a file descriptor
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
