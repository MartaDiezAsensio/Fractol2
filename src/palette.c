/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:56:41 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/24 16:50:15 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stddef.h>

// Build color palette for the fractals
t_palette	*get_palettes(void)
{
	static t_palette	array[5];

	array[0]
		= (t_palette){5, 0, {0xE6E1C5, 0xD4CB92, 0x395C6B, 0x80A4ED, 0x80A4ED}};
	array[1]
		= (t_palette){5, 0, {0x04080F, 0x507DBC, 0xA1C6EA, 0xBBD1EA, 0xDAE3E5}};
	array[2]
		= (t_palette){5, 0, {0xE6E1C5, 0xD4CB92, 0x395C6B, 0x80A4ED, 0xBCD3F2}};
	array[3]
		= (t_palette){7, 10, {0x34F6F2, 0x78E3FD, 0xD1F5FF, 0xEEF8FF,
		0x7D53DE, 0x7D53DE, 0x7D53DE}};
	array[4] = (t_palette){0, 0, {0}};
	return (array);
}
