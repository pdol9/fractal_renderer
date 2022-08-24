/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/07/18 15:23:24 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_set(t_fractol *data)
{
	t_color	trgb;
	int		new_color;
	int		palette[8];
	int		*p;

	p = palette;
	palette[0] = 0x00333333;
	palette[1] = 0x0033FF33;
	palette[2] = 0x00FF7F00;
	palette[3] = 0x00CCCC00;
	palette[4] = 0x00FF6666;
	palette[5] = 0x004B0082;
	palette[6] = 0x00FF0000;
	palette[7] = 0x006C6CFF;
	retrieve_trgb(data, &trgb, p);
	trgb.tt = interpolate(trgb.in_t, trgb.in_t2, data->iter);
	trgb.rr = interpolate(trgb.in_r, trgb.in_r2, data->iter);
	trgb.gg = interpolate(trgb.in_g, trgb.in_g2, data->iter);
	trgb.bb = interpolate(trgb.in_b, trgb.in_b2, data->iter);
	new_color = retrieve_color(trgb);
	return (new_color);
}

void	retrieve_trgb(t_fractol *data, t_color *trgb, int *p)
{
	trgb->color1 = DEFAULT;
	trgb->in_t = (trgb->color1 >> 24) & 0xFF;
	trgb->in_r = (trgb->color1 >> 16) & 0xFF;
	trgb->in_g = (trgb->color1 >> 8) & 0xFF;
	trgb->in_b = (trgb->color1) & 0xFF;
	trgb->in_t2 = ((p[data->col_num]) >> 24) & 0xFF;
	trgb->in_r2 = ((p[data->col_num]) >> 16) & 0xFF;
	trgb->in_g2 = ((p[data->col_num]) >> 8) & 0xFF;
	trgb->in_b2 = ((p[data->col_num])) & 0xFF;
}

int	retrieve_color(t_color trgb)
{
	return (trgb.tt << 24 | trgb.rr << 16 | trgb.gg << 8 | trgb.bb);
}

double	interpolate(double offset, double end, int t)
{
	return (offset + (end - offset) * t);
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}
