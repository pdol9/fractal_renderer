/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2023/08/23 21:44:43 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	(*f(int num))(t_fractol *data)
{
	if (num == 0)
		return (mandelbrot_set);
	if (num == 1)
		return (julia_set);
	if (num == 2)
		return (burning_ship_set);
	return (NULL);
}

void	reset_fractal_pos(t_fractol *data)
{
	void	(*def_set[3])();

	def_set[0] = &init_set_m;
	def_set[1] = &init_set_j;
	def_set[2] = &init_set_s;
	def_set[data->fract_num](data);
}

void	switch_fractal_set(t_fractol *data)
{
	if (data->fract_num < 2)
		data->fract_num++;
	else
		data->fract_num = 0;
	reset_fractal_pos(data);
}

void	switch_color(t_fractol *data)
{
	if (data->col_num < 7)
		data->col_num++;
	else
		data->col_num = 0;
}

int	clear_mlx(t_fractol *data)
{
	if (data->mlx_ptr && data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->mlx_ptr && data->win)
		mlx_destroy_window(data->mlx_ptr, data->win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
