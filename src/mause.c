/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:55:57 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/18 19:33:59 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//mlx->mouse.isdown |= 1 << button;
int	hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (button = 4)
	{
		zoom(x, y, &mlx->viewport, 1 / ZOOM);
		render(mlx);
	}
	else if (button = 3)
	{
		zoom(x, y, &mlx->viewport, ZOOM);
		render(mlx);
	}
	if (y < 0)
		return (0);
	mlx->mouse.isdown |= 1 << button;
	return (0);
}

//mlx->mouse.isdown &= ~(1 << button);
int	hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.isdown &= ~(1 << button);
	return (0);
}

// Description
int	hook_mousemove(int x, int y, t_mlx *mlx)
{
	double	w;
	double	h;

	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (!mlx->mouselock)
		mlx->viewport.mouse = screen_to_complex(x, y, &mlx->viewport);
	if (mlx->mouse.isdown & (1 << 1))
	{
		w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
		y = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
		mlx->viewport.offx += (double)(mlx->mouse.lastx - mlx->mouse.x) / WIN_WIDTH * w;
		mlx->viewport.offy += (double)(mlx->mouse.lasty - mlx->mouse.y) / WIN_HEIGHT * h;
	}
	if (mlx->mouse.isdown || (mlx->fractal->mouse && !mlx->mouselock))
		render(mlx);
	return(0);
}