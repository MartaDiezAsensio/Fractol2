/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:30:36 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/21 17:07:26 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Fit the height and width of the screen
void	viewport_fit(t_viewport *viewport)
{
	double	w;
	double	h;

	w = viewport->xmax - viewport->xmin;
	h = viewport->ymax - viewport->ymin;
	if (w / h >= (float)WIN_WIDTH / WIN_HEIGHT)
	{
		viewport->ymin = -(w * WIN_HEIGHT / WIN_WIDTH / 2);
		viewport->ymax = w * WIN_HEIGHT / WIN_WIDTH / 2;
	}
	else
	{
		viewport->xmin = -(h * WIN_WIDTH / WIN_HEIGHT / 2);
		viewport->max = h * WIN_WIDTH / WIN_HEIGHT / 2;
	}
}

// Reset viewport configuration
void	reset_viewport(t_mlx *mlx)
{
	mlx->viewport.offx = 0;
	mlx->viewport.offy = 0;
	mlx->fractal->viewport(&mlx->viewport);
	viewport_fit(&mlx->viewport);
	mlx->viewport.max = 32;
	mlx->viewport.zoom = 1.0f;
}

// Put in screen a complex number
t_complex	screen_to_complex(int x, int y, t_viewport *viewport)
{
	t_complex	p;

	p.r = (((double)x / WIN_WIDTH) * (viewport->xmax - viewport->xmin)) * viewport->zoom 
		+ viewport->xmin + viewport->offx;
	p.i = (((double)y / WIN_HEIGHT) * (viewport->ymax - viewport->ymin)) * viewport->zoom
		+ viewport->ymin + viewport->offy;
	return (p);
}
