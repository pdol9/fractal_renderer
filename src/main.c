/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:49:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/07/18 15:23:37 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_rendering(t_fractol *data)
{
	void	(*f[3])();

	f[0] = &mandelbrot_set;
	f[1] = &julia_set;
	f[2] = &burning_ship_set;
	data->x = 0;
	while (data->x < WINDOW_HEIGHT)
	{
		data->y = 0;
		while (data->y < WINDOW_WIDTH)
		{
			data->r = data->min_x + data->x * (data->max_x - data->min_x)
				/ WINDOW_WIDTH;
			data->i = data->min_y + data->y * (data->max_y - data->min_y)
				/ WINDOW_HEIGHT;
			f[data->fract_num](data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	handle_input(argc, argv, &data);
	init_mlx(&data);
	init_fractol(&data);
	msg();
	fractol_rendering(&data);
	mlx_hook(data.win, 2, 1L << 0, &handle_keypress, &data);
	mlx_mouse_hook(data.win, &mouse_event, &data);
	mlx_hook(data.win, 6, 0, &julia_move, &data);
	mlx_hook(data.win, 17, 1L << 2, &clear_mlx, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
