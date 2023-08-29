/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2023/08/29 20:35:54 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_color_value(t_fractol *data)
{
	t_color	trgb;
	int		new_color;

	retrieve_trgb(data, &trgb);
	trgb.tt = interpolate(trgb.in_t, trgb.in_t2, data->iter);
	trgb.rr = interpolate(trgb.in_r, trgb.in_r2, data->iter);
	trgb.gg = interpolate(trgb.in_g, trgb.in_g2, data->iter);
	trgb.bb = interpolate(trgb.in_b, trgb.in_b2, data->iter);
	new_color = retrieve_color(trgb);
	return (new_color);
}

void	retrieve_trgb(t_fractol *data, t_color *trgb)
{
	trgb->in_t = (DEFAULT >> 24) & 0xFF;
	trgb->in_r = (DEFAULT >> 16) & 0xFF;
	trgb->in_g = (DEFAULT >> 8) & 0xFF;
	trgb->in_b = DEFAULT & 0xFF;
	trgb->in_t2 = ((data->palette[data->col_num]) >> 24) & 0xFF;
	trgb->in_r2 = ((data->palette[data->col_num]) >> 16) & 0xFF;
	trgb->in_g2 = ((data->palette[data->col_num]) >> 8) & 0xFF;
	trgb->in_b2 = ((data->palette[data->col_num])) & 0xFF;
}

double	interpolate(double offset, double end, int t)
{
	return (offset + (end - offset) * t);
}

int	retrieve_color(t_color trgb)
{
	return (trgb.tt << 24 | trgb.rr << 16 | trgb.gg << 8 | trgb.bb);
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x \
			* (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}
