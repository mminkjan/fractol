/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 12:03:57 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 22:41:45 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		get_bit_value(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static void		set_color_to_end(t_color *color, t_events *events)
{
	if (events->color_set == 0)
	{
		color->start = ONE_MIDDLE;
		color->end = ONE_END;
	}
	if (events->color_set == 1)
	{
		color->start = TWO_MIDDLE;
		color->end = TWO_END;
	}
	if (events->color_set == 2)
	{
		color->start = THREE_MIDDLE;
		color->end = THREE_END;
	}
}

static void		set_color_to_mid(t_color *color, t_events *events)
{
	if (events->color_set == 0)
	{
		color->start = ONE_START;
		color->end = ONE_MIDDLE;
	}
	if (events->color_set == 1)
	{
		color->start = TWO_START;
		color->end = TWO_MIDDLE;
	}
	if (events->color_set == 2)
	{
		color->start = THREE_START;
		color->end = THREE_MIDDLE;
	}
	// else
	// {
	// 	color->end = DEFAULT_MIDDLE;
	// 	color->start = DEFAULT_END;
	// }
}

static int		rgb_color(t_fractol *fractol, double iteration)
{
	double	percentage;
	t_color color;
	int		red;
	int		green;
	int		blue;

	if (iteration < fractol->max_iterations / 4)
	{
		set_color_to_mid(&color, &fractol->event);
		percentage = iteration / (fractol->max_iterations / 4);
	}
	else
	{
		set_color_to_end(&color, &fractol->event);
		percentage = iteration / fractol->max_iterations;
	}
	red = get_bit_value(\
		(color.start >> 16) & 0xFF, (color.end >> 16) & 0xFF, percentage);
	green = get_bit_value(\
		(color.start >> 8) & 0xFF, (color.end >> 8) & 0xFF, percentage);
	blue = get_bit_value(color.start & 0xFF, color.end & 0xFF, percentage);
	return (red << 16 | green << 8 | blue);
}

static double	smooth_color(t_fractol *fractol, double iterations)
{
	double		complex;
	double		nb;
	double		new_i;
	double		real;
	double		i;

	real = fractol->pixel->c.r;
	i = fractol->pixel->c.i;
	complex = log(real * real + i * i) / 2.0f;
	nb = log(complex / log(2)) / log(2);
	new_i = iterations + 1 - nb;
	if (new_i < 0)
		new_i = 0;
	return (new_i);
}

int				get_color(t_fractol *fractol, double iterations)
{
	if (fractol->event.color_grade == 0)
		iterations = smooth_color(fractol, iterations);
	return (rgb_color(fractol, iterations));
}
