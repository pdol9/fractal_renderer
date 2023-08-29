/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2023/08/29 20:37:15 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_fractol *data, int key)
{
	data->center_x = data->max_x - data->min_x;
	data->center_y = data->max_y - data->min_y;
	if (key == KEY_W)
	{
		data->max_y += data->center_y * 0.1;
		data->min_y += data->center_y * 0.1;
	}
	if (key == KEY_A)
	{
		data->max_x += data->center_x * 0.1;
		data->min_x += data->center_x * 0.1;
	}
	if (key == KEY_S)
	{
		data->max_y -= data->center_y * 0.1;
		data->min_y -= data->center_y * 0.1;
	}
	if (key == KEY_D)
	{
		data->max_x -= data->center_x * 0.1;
		data->min_x -= data->center_x * 0.1;
	}
}

int	mouse_event(int button, int x, int y, void *data)
{
	if (x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return (1);
	if (button == M_UP)
		zoom(data, -2.0);
	else if (button == M_DOWN)
		zoom(data, 0.6);
	else
		return (1);
	fractol_rendering(data);
	return (0);
}

int	julia_move(int x, int y, void *data)
{
	t_fractol	*tmp;
	double		offset;
	double		center;

	tmp = (t_fractol *)data;
	if (tmp->fract_num != 1)
		return (1);
	center = tmp->max_x - tmp->min_x;
	offset = tmp->min_x;
	tmp->kx = offset + x * center / WINDOW_WIDTH;
	center = tmp->max_y - tmp->min_y;
	offset = tmp->min_y;
	tmp->ky = offset + y * center / WINDOW_HEIGHT;
	fractol_rendering(data);
	return (0);
}

void	zoom(t_fractol *data, double factor)
{
	double	center_x;
	double	center_y;

	center_x = data->max_x - data->min_x;
	center_y = data->max_y - data->min_y;
	data->max_x = data->max_x - center_x * factor * -0.1;
	data->min_x = data->min_x + center_x * factor * -0.1;
	data->max_y = data->max_y - center_y * factor * -0.1;
	data->min_y = data->min_y + center_y * factor * -0.1;
}

int	handle_keypress(int key, void *data)
{
	if (key == KEY_ESC)
		clear_mlx(data);
	if (key == KEY_W)
		move(data, key);
	if (key == KEY_A)
		move(data, key);
	if (key == KEY_S)
		move(data, key);
	if (key == KEY_D)
		move(data, key);
	if (key == KEY_R)
		reset_fractal_pos(data);
	if (key == KEY_SPACE)
		switch_fractal_set(data);
	if (key == KEY_ENTER)
		switch_color(data);
	if (key == KEY_DOWN)
		zoom(data, 0.4);
	if (key == KEY_UP)
		zoom(data, -2.0);
	fractol_rendering(data);
	return (0);
}
