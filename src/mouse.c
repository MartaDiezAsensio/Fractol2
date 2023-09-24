/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:55:57 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/24 16:50:05 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
BINARY OPERATIONS
- 1 << button: Left-shift the binary number 1 by the value of the button value.
It sets the button-th bit to 1 and the rest to 0s.
- ~(1 << button): Inverts all ht bits of the result obtained in the step 
(1 << button).
Invers the 0s and 1s.
- &= ~(1 << button): bitwise and assignment operation. 
*/

int	hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		zoom(x, y, &mlx->viewport, 1 / ZOOM);
		render(mlx);
	}
	else if (button == 5)
	{
		zoom(x, y, &mlx->viewport, ZOOM);
		render(mlx);
	}
	if (y < 0)
		return (0);
	mlx->mouse.isdown |= 1 << button;
	return (0);
}

int	hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.isdown &= ~(1 << button);
	return (0);
}

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
		w = (mlx->viewport.xmax - mlx->viewport.xmin)
			* mlx->viewport.zoom;
		h = (mlx->viewport.ymax - mlx->viewport.ymin)
			* mlx->viewport.zoom;
		mlx->viewport.offx += (double)(mlx->mouse.lastx - mlx->mouse.x)
			/ WIN_WIDTH * w;
		mlx->viewport.offy += (double)(mlx->mouse.lasty - mlx->mouse.y)
			/ WIN_HEIGHT * h;
	}
	if (mlx->mouse.isdown || (mlx->fractal->mouse && !mlx->mouselock))
		render(mlx);
	return (0);
}
