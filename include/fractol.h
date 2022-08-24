/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/07/18 14:49:47 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <libft.h>

# define WINDOW_WIDTH	900
# define WINDOW_HEIGHT	900
# define MAX_ITER		80
# define DEFAULT		0x00000000

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_DOWN	125
# define M_UP		5
# define M_DOWN		4
# define KEY_ENTER	36
# define KEY_R		15
# define KEY_SPACE	49

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
	int			color1;
	int			color2;
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
	void		*mlx_ptr;
	void		*win;
	t_image		img;
	double		max_x;
	double		min_x;
	double		max_y;
	double		min_y;
	int			fract_num;
	int			col_num;
	int			iter;
	double		center_x;
	double		center_y;
	double		x;
	double		y;
	double		r;
	double		i;
	double		kx;
	double		ky;
	int			jstart;
}	t_fractol;

/* sets */
void	mandelbrot_set(t_fractol *data);
void	burning_ship_set(t_fractol *data);
void	julia_set(t_fractol *data);

/* utils */
void	zoom(t_fractol *data, double factor);
void	move(t_fractol *data, int key);
void	change_set(t_fractol *data);
void	julia_args(int argc, char **argv, t_fractol *data);
int		color_set(t_fractol *data);
void	handle_input(int argc, char **argv, t_fractol *data);
void	handle_error(int value);
double	interpolate(double color1, double color2, int t);
void	clearing_img(t_fractol *data);
void	change_color(t_fractol *data);
int		retrieve_color(t_color trgb);
void	retrieve_trgb(t_fractol *data, t_color *trgb, int *p);
void	put_pixel(t_image *img, int x, int y, int color);

/* fractol hook func */
int		msg(void);
int		fractol_rendering(t_fractol *data);
int		handle_keypress(int key, void *data);
int		mouse_event(int button, int x, int y, void *data);
int		julia_move(int x, int y, void *data);
int		clear_mlx(t_fractol *data);

/* init functions */
void	init_mlx(t_fractol *data);
void	init_fractol(t_fractol *data);
void	init_set_m(t_fractol *data);
void	init_set_j(t_fractol *data);
void	init_set_s(t_fractol *data);

#endif
