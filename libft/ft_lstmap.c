/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:25:11 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/24 16:28:03 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;
	t_list	*tmp;

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
