/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:25:11 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/29 16:55:14 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

s_list	*ft_lstmap(s_list *lst, void *(*f)(void *), void (*del)(void *))
{
	s_list	*new;
	s_list	*aux;
	s_list	*tmp;

	if (!(lst))
		return (NULL);
	new = 0;
	while (lst)
	{
		tmp = f(lst->content);
		aux = ft_lstnew(tmp);
		if (!(aux))
		{
			del(tmp);
			ft_lstclear(&new, del);
		}
		ft_lstadd_back(&new, aux);
		lst = lst->next;
	}
	return (new);
}
