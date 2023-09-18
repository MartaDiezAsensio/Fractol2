/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:16:20 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/18 18:54:14 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

// Zoom configuration - From height and width to new height and width
void	zoom(int x, int y, t_viewport *viewport, double z)
{
	double	w;
	double	h;
	double	nw;
	double	nh;

	w = (viewport->xmax - viewport->xmin) * (viewport->zoom);
	h = (viewport->ymax - viewport->ymin) * (viewport->zoom);
	nw = (viewport->xmax - viewport->xmin) * (viewport->zoom * z);
	nh = (viewport->ymax - viewport->ymin) * (viewport->zoom * z);
	viewport->zoom *= z;
	viewport->offx = ((double)x / WIN_WIDTH) * (nw - w);
	viewport->offy = ((double)y / WIN_HEIGHT) * (nh - h);
}