/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/07/18 15:23:33 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *data)
{
	void	(*def_set[3])();

	def_set[0] = &init_set_m;
	def_set[1] = &init_set_j;
	def_set[2] = &init_set_s;
	clearing_img(data);
	def_set[data->fract_num](data);
}

void	init_set_m(t_fractol *data)
{
	data->max_x = 1.0;
	data->min_x = -2.0;
	data->min_y = -1.5;
	data->max_y = 1.5;
}

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

void	init_set_s(t_fractol *data)
{
	data->max_x = 1.5;
	data->min_x = -2.0;
	data->min_y = -1.8;
	data->max_y = 2.0;
}

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
}
