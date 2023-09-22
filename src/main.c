/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:16:43 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/21 17:07:41 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include "../MinilibX/mlx.h"

int	hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

int	die(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractal	*f;

	if (argc < 2)
		return (die("error: not enough arguments"));
	f = fractal_match(argv[1]);
	if (f->name == NULL)
		return (die("error: invalid fractal name"));
	if ((mlx = init(f)) == NULL)
		return (die("error: mlx couldn't initialize properly"));
	reset_viewport(mlx);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
