/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hsv_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 22:32:40 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/27 19:58:05 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	rgb(float r, float g, float b)
{
	r *= 255;
	g *= 255;
	b *= 255;
	return ((int)r << 16 | (int)g << 8 | (int)b);
}

static int	hsv_to_rgb(float h, float s, float v)
{
	int			index;
	float		f;
	float		p;
	float		q;
	float		t;

	if (s == 0)
		return ((int)v | (int)v | (int)v);
	h /= 60;
	index = floor(h);
	f = h - index;
	p = v * (1.f - s);
	q = v * (1.f - s * f);
	t = v * (1.f - s * (1.f - f));
	if (index == 0)
		return (rgb(v, t, p));
	else if (index == 1)
		return (rgb(q, v, p));
	else if (index == 2)
		return (rgb(p, v, t));
	else if (index == 3)
		return (rgb(p, q, v));
	else if (index == 4)
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
