/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2023/08/29 20:38:55 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_set(t_fractol *data)
{
	double	a;
	double	bi;
	double	new_z;

	a = 0;
	bi = 0;
	data->iter = 0;
	while (data->iter < MAX_ITER)
	{
		if ((a * a + bi * bi) > 4)
			break ;
		new_z = 2 * a * bi + data->i;
		a = a * a - bi * bi + data->r;
		bi = new_z;
		++data->iter;
	}
	put_pixel(&(data->img), data->x, data->y, set_color_value(data));
}

void	burning_ship_set(t_fractol *data)
{
	double	a;
	double	bi;
	double	new_z;

	a = 0;
	bi = 0;
	data->iter = 0;
	while (data->iter < MAX_ITER)
	{
		if ((a * a + bi * bi) > 4)
			break ;
		a = fabs(a);
		bi = fabs(bi);
		new_z = 2 * a * bi + data->i;
		a = a * a - bi * bi + data->r;
		bi = new_z;
		++data->iter;
	}
	put_pixel(&(data->img), data->x, data->y, set_color_value(data));
}

void	julia_set(t_fractol *data)
{
	double	new_z;

	data->iter = 0;
	while (data->iter < MAX_ITER)
	{
		if ((data->r * data->r + data->i * data->i) > 4)
			break ;
		new_z = 2 * data->r * data->i + data->ky;
		data->r = data->r * data->r - data->i * data->i + data->kx;
		data->i = new_z;
		++data->iter;
	}
	put_pixel(&(data->img), data->x, data->y, set_color_value(data));
}
