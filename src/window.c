/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:59:57 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/21 17:07:22 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include "../MinilibX/mlx.h"

// Delete mlx window
t_mlx	*mlxdel(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

// Initialize mlx window with specific fractal and palette
t_mlx	*init(t_fractal *fractal)
{
	t_mlx	*mlx;
	char	*title;

	mlx = ft_memalloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	title = ft_strjoin("Fract'ol - ", fractal->name);
	if (!(mlx->mlx = mlx_init()) ||
	!(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, title)) ||
	!(mlx->image = new_image(mlx)) ||
	!(mlx->data = ft_memalloc(sizeof(t_pixel) * WIN_WIDTH * WIN_HEIGHT)))
		return (mlxdel(mlx));
	mlx->mouse.isdown = 0;
	mlx->fractal = fractal;
	mlx->mouselock = 1 - fractal->mouse;
	mlx->palette = get_palettes();
	mlx->smooth = 1;
	return (mlx);
}
