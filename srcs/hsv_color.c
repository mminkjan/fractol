/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hsv_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 22:32:40 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/27 16:46:51 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	rgb(double r, double g, double b)
{
	r *= 255;
	g *= 255;
	b *= 255;
	return ((int)r << 16 | (int)g << 8 | (int)b);
}

static int	hsv_to_rgb(double h, double s, double v)
{
	int			i;
	double		f;
	double		p;
	double		q;
	double		t;

	if (s == 0)
		return ((int)v | (int)v | (int)v);
	h /= 60;
	i = floor(h);
	f = h - i;
	p = v * (1.f - s);
	q = v * (1.f - s * f);
	t = v * (1.f - s * (1.f - f));
	if (i == 0)
		return (rgb(v, t, p));
	else if (i == 1)
		return (rgb(q, v, p));
	else if (i == 2)
		return (rgb(p, v, t));
	else if (i == 3)
		return (rgb(p, q, v));
	else if (i == 4)
		return (rgb(t, p, v));
	return (rgb(v, p, q));
}

int			hsv_color(double iterations)
{
	t_color		color;

	if (iterations < 40)
		color.hue = (int)((360 - 150) * (iterations / 40));
	else
		color.hue = (int)(360 * (iterations / 150));
	color.saturation = 1;
	color.value = 1;
	return (hsv_to_rgb(color.hue, color.saturation, color.value));
}
