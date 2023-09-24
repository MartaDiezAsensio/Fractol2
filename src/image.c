/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:47:51 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/24 16:48:04 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/libft.h"
#include "../MinilibX/mlx.h"

// Set image and color
void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(image->ptr + ((x + y * WIN_WIDTH) * image->bpp)) = color;
}

// Function to clear image
void	clear_image(t_image *image)
{
	ft_bzero(image->ptr, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

// Function to delete the image
t_image	*del_image(t_mlx *mlx, t_image *img)
{
	if (img != NULL)
	{
		if (img->image != NULL)
			mlx_destroy_image(mlx->mlx, img->image);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

// Function to create new image
t_image	*new_image(t_mlx *mlx)
{
	t_image	*img;

	img = ft_memalloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!(img->image))
		return (del_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
			&img->endian);
	img->bpp /= 8;
	return (img);
}
