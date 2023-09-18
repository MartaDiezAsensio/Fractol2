/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:20:23 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/24 22:34:54 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	val;
	int	res;

	val = c ;
	res = 0;
	if (val >= '0' && val <= '9')
		res = 1;
	else
	{
		while (val > 0)
		{
			if ((val % 10) >= 0 && (val % 10) <= 9)
				res = 0;
			else
				res = 1;
			val /= 10;
		}
	}
	return (res);
}
