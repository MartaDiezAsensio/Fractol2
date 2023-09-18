/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:22:19 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/24 22:38:16 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*aux;

	res = NULL;
	aux = (char *)s;
	while (*aux)
	{
		if (*aux == (char)c)
			res = aux;
		aux++;
	}
	if ((char)c == '\0')
		return (aux);
	return (res);
}
