/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/07/18 15:23:53 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clearing_img(t_fractol *data)
{
	data->x = 0;
	while (data->x++ < WINDOW_HEIGHT)
	{
		data->y = 0;
		while (data->y++ < WINDOW_WIDTH)
			put_pixel(&(data->img), data->x, data->y, DEFAULT);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->img.img_ptr, 0, 0);
}

void	change_set(t_fractol *data)
{
	if (data->fract_num < 2)
		data->fract_num++;
	else
		data->fract_num = 0;
	init_fractol(data);
}

void	change_color(t_fractol *data)
{
	if (data->col_num < 8)
		data->col_num++;
	else
		data->col_num = 0;
	clearing_img(data);
}

int	clear_mlx(t_fractol *data)
{
	if (data->mlx_ptr && data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->mlx_ptr && data->win)
		mlx_destroy_window(data->mlx_ptr, data->win);
	exit(0);
	return (0);
}
