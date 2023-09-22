/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:00:06 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/22 19:54:07 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"

t_fractal	*get_fractals(void)
{
	static t_fractal array[8] = {
		{"mandelbrot", mandelbrot_viewport, mandelbrot_pixel, 0},
		{"julia", julia_viewport, julia_pixel, 1},
		{"burningship", burningship_viewport, burningship_pixel, 0},
		{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}
