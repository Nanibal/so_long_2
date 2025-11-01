/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 09:24:19 by nayala            #+#    #+#             */
/*   Updated: 2025-04-14 09:24:19 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//free the memory of a node in the list
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free (lst);
}
