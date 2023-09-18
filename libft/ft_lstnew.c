/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:24:34 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/29 16:55:25 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

s_list	*ft_lstnew(void *content)
{
	s_list	*res;

	res = (s_list *)malloc(sizeof(*res));
	if (!(res))
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
