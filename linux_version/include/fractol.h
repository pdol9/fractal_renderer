/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2024/04/22 19:42:02 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <libft.h>
# include "../mlx/mlx.h"

# define WINDOW_WIDTH	600
# define WINDOW_HEIGHT	600
# define MAX_ITER		90
# define DEFAULT		0x0

# define M_UP			5
# define M_DOWN			4

# define KEY_ESC		65307
# define KEY_S			119
# define KEY_D			97
# define KEY_W			115
# define KEY_A			100
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_ENTER		65293
# define KEY_R			114
# define KEY_SPACE		32

typedef struct s_color
{
	double		in_t;
	double		in_r;
	double		in_g;
	double		in_b;
	double		in_t2;
	double		in_r2;
	double		in_g2;
	double		in_b2;
	int			tt;
	int			rr;
	int			gg;
	int			bb;
}	t_color;

typedef struct s_image
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_fractol
{
	t_image		img;
	void		*mlx_ptr;
	void		*win;
	double		max_x;
	double		min_x;
	double		max_y;
	double		min_y;
	double		center_x;
	double		center_y;
	double		x;
	double		y;
	double		r;
	double		i;
	double		kx;
	double		ky;
	int			jstart;
	int			fract_num;
	int			col_num;
	int			iter;
	int			palette[8];
}	t_fractol;

/* sets */
void	mandelbrot_set(t_fractol *data);
void	burning_ship_set(t_fractol *data);
void	julia_set(t_fractol *data);

/* utils */
void	(*f(int num))(t_fractol *data);
void	reset_fractal_pos(t_fractol *data);
void	switch_fractal_set(t_fractol *data);
void	switch_color(t_fractol *data);

/* rendering */
int		set_color_value(t_fractol *data);
double	interpolate(double color1, double color2, int t);
int		retrieve_color(t_color trgb);
void	retrieve_trgb(t_fractol *data, t_color *trgb);
void	put_pixel(t_image *img, int x, int y, int color);

/* fractol hook func */
int		fractol_rendering(t_fractol *data);
int		handle_keypress(int key, void *data);
int		mouse_event(int button, int x, int y, void *data);
int		julia_move(int x, int y, void *data);
int		clear_mlx(t_fractol *data);
int		msg(void);

void	mapping_pixels(t_fractol *data);
void	zoom(t_fractol *data, double factor);
void	move(t_fractol *data, int key);

/* init functions */
void	init_mlx(t_fractol *data);
void	init_set_m(t_fractol *data);
void	init_set_j(t_fractol *data);
void	init_set_s(t_fractol *data);
void	initialize_palette(t_fractol *data);

/* error handling */
void	julia_args(int argc, char **argv, t_fractol *data);
void	handle_input(int argc, char **argv, t_fractol *data);
void	handle_error(int value);

#endif
