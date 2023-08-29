/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:49:33 by pdolinar          #+#    #+#             */
/*   Updated: 2023/08/29 20:11:29 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	data;

	handle_input(argc, argv, &data);
	init_mlx(&data);
	msg();
	fractol_rendering(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_mouse_hook(data.win, &mouse_event, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, &julia_move, &data);
	mlx_hook(data.win, DestroyNotify, ButtonPressMask, &clear_mlx, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int	fractol_rendering(t_fractol *data)
{
	mlx_clear_window(data->mlx_ptr, data->win);
	data->x = 0;
	while (data->x < WINDOW_HEIGHT)
	{
		data->y = 0;
		while (data->y < WINDOW_WIDTH)
		{
			mapping_pixels(data);
			f(data->fract_num)(data);
			++data->y;
		}
		++data->x;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

void	mapping_pixels(t_fractol *data)
{
	data->r = data->min_x + data->x * (data->max_x - data->min_x) \
		/ WINDOW_WIDTH;
	data->i = data->min_y + data->y * (data->max_y - data->min_y) \
		/ WINDOW_HEIGHT;
}
