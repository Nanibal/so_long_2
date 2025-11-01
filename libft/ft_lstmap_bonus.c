/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 09:51:29 by nayala            #+#    #+#             */
/*   Updated: 2025-04-14 09:51:29 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//create a new list with the conent of the orginal with the function apply
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*new;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		elem = ft_lstnew(new_content);
		if (!elem)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, elem);
		lst = lst -> next;
	}
	return (new);
}
