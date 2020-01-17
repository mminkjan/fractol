/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_color2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 12:47:19 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/17 18:25:31 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			hsv_to_rgb(float h, float s, float v)
{
	int			i;
	float		f;
	float		p;
	float		q;
	float		t;

	if (s == 0)
		return ((int)v | (int)v | (int)v);
	h /= 60;
	i = floor(h);
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - f * s);
	t = v * (1 - (1 - f) * s);
	if (i == 0)
		return ((int)v | (int)t | (int)p);
	else if (i == 1)
		return ((int)q | (int)v | (int)p);
	else if (i == 2)
		return ((int)p | (int)v | (int)t);
	else if (i == 3)
		return ((int)p | (int)q | (int)v);
	else if (i == 4)
		return ((int)t | (int)p | (int)v);
	return ((int)v | (int)p | (int)q);
}

float	scale(float x, float max_in,
	float max_out)
{
	return (x * max_out / max_in);
}

int		get_color(t_fractol *fractol, int iteration)
{
	float		h;
	float		s;
	float		v;

	(void)fractol;
	h = 0;
	s = scale(iteration * 10, MAX_ITERATIONS, 360);
	v = scale(iteration * 100, MAX_ITERATIONS, 360);
	h = scale(h, 360, 255);
	s = scale(s, 100, 255);
	v = scale(v, 100, 255);
	return (hsv_to_rgb(h, s, v));
}
