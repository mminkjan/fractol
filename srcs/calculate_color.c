/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_color.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 12:47:19 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/18 20:31:53 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			hsv_to_rgb(float *h, float *s, float *v)
{
	int			i;
	float		f;
	float		p;
	float		q;
	float		t;

	if (s == 0)
		return ((int)*v | (int)*v | (int)*v);
	*h /= 60;
	i = floor(*h);
	f = *h - i;
	p = *v * (1 - (*s));
	q = *v * (1 - f * (*s));
	t = *v * (1 - (1 - f) * (*s));
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
	t_color		color;
	float		percent;		

	color = fractol->color;
	color.hue = 0xc31432;
	if (iteration < fractol->max_iterations / 4)
	{
		percent = scale(iteration, fractol->max_iterations, fractol->max_iterations / 4);
		color.hue = fractol->color.start;
	}
	else
	{
		percent = scale(iteration, fractol->max_iterations, (fractol->max_iterations - fractol->max_iterations / 4));
		color.hue = fractol->color.end;
	}
	// color.saturation = scale(percent * color.saturation, fractol->max_iterations, 360);
	// if (color.saturation <= 5.0)
	// 	color.saturation = 10;
	// color.value = scale(percent * color.value, fractol->max_iterations, 360);
	// if (color.value <= 0.0)
	// 	color.value = 10;
	color.hue = scale(color.hue, 360, 255);
	color.saturation = scale(color.saturation * percent, 100, 255);
	color.value = scale(color.value, 100, 255);
	return (hsv_to_rgb(&color.hue, &color.saturation, &color.value));
}
