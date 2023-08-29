/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2023/08/23 21:11:13 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* initialize Mandelbrot set */
void	init_set_m(t_fractol *data)
{
	data->max_x = 1.0;
	data->min_x = -2.0;
	data->min_y = -1.5;
	data->max_y = 1.5;
}

/* initialize Julia set */
void	init_set_j(t_fractol *data)
{
	data->max_x = 2.0;
	data->min_x = -2.0;
	data->min_y = -2.0;
	data->max_y = 2.2;
	if (data->jstart)
		return ;
	data->kx = -0.766667;
	data->ky = -0.090000;
}

/* initialize burning ship set */
void	init_set_s(t_fractol *data)
{
	data->max_x = 1.5;
	data->min_x = -2.0;
	data->min_y = -1.8;
	data->max_y = 2.0;
}

/* initialize main struct */
void	init_mlx(t_fractol *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		clear_mlx(data);
	data->win = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "fract'ol");
	if (data->win == NULL)
		clear_mlx(data);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	data->col_num = 0;
	if (data->fract_num != 1)
		data->jstart = 0;
	initialize_palette(data);
	reset_fractal_pos(data);
}

/* initialize color pelette */
void	initialize_palette(t_fractol *data)
{
	data->palette[0] = 0x00333333;
	data->palette[1] = 0x0033FF33;
	data->palette[2] = 0x00FF7F00;
	data->palette[3] = 0x00CCCC00;
	data->palette[4] = 0x00FF6666;
	data->palette[5] = 0x004B0082;
	data->palette[6] = 0x00FF0000;
	data->palette[7] = 0x006C6CFF;
}
