/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:28:39 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/09/19 19:29:27 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <pthread.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define ZOOM 1.1f
# define THREADS 8

// Structure to define rgba color palette
typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

// Structure for color
typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

// Structure for mouse events
typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

// Structue for image definition
typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

// Structure for complex number definition
typedef struct		s_complex
{
	double		r;
	double		i;
}					t_complex;

// Structure for viewport definition (screen)
typedef struct		s_viewport
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	t_complex	mouse;
}					t_viewport;

// Structure to define the value of a pixel
typedef struct		s_pixel
{
	t_complex	c;
	long		i;
}					t_pixel;

// Structure for color palette definition
typedef struct		s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palette;

typedef struct s_mlx	t_mlx;

typedef void		(*t_f_fn_v)(t_viewport *v);
typedef t_pixel		(*t_f_fn_p)(int x, int y, t_viewport *v, t_mlx *mlx);

//Strcuture for fractal definition
typedef struct		s_fractal
{
	char		*name;
	t_f_fn_v	viewport;
	t_f_fn_p	pixel;
	int			mouse;
}					t_fractal;

// Structure for thread definition
typedef struct		s_thread
{
	int				id;
	t_mlx			*mlx;
}					t_thread;

// Structure for rendering definition
typedef struct		s_render
{
	pthread_t		threads[THREADS];
	t_thread		args[THREADS];
}					t_render;

// Structure for mlx Library
struct				s_mlx
{
	void		*mlx;
	void		*window;
	t_fractal	*fractal;
	t_pixel		*data;
	t_image		*image;
	t_mouse		mouse;
	t_viewport	viewport;
	t_palette	*palette;
	t_render	render;
	int			smooth;
	int			mouselock;
};

t_mlx				*mlxdel(t_mlx *mlx);
t_mlx				*init(t_fractal *f);
void				render(t_mlx *mlx);
void				draw(t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_expose(t_mlx *mlx);
t_image				*del_image(t_mlx *mlx, t_image *img);
t_image				*new_image(t_mlx *mlx);
void				clear_image(t_image *img);
void				image_set_pixel(t_image *image, int x, int y, int color);
t_fractal			*fractal_match(char *str);
int					get_color(t_pixel p, t_mlx *mlx);
t_palette			*get_palettes();
void				zoom(int x, int y, t_viewport *v, double z);
void				viewport_fit(t_viewport *v);
void				reset_viewport(t_mlx *mlx);
t_complex			screen_to_complex(int x, int y, t_viewport *v);
t_pixel				mandelbrot_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				mandelbrot_viewport(t_viewport *v);
t_pixel				burningship_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				burningship_viewport(t_viewport *v);
t_pixel				julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				julia_viewport(t_viewport *v);

#endif