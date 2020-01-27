/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:35:13 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/27 12:35:12 by jesmith       ########   odam.nl         */
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
		color->start = ONE_END;
		color->end = ONE_MIDDLE;
	}
	if (events->color_set == 1)
	{
		color->start = TWO_END;
		color->end = TWO_MIDDLE;
	}
	if (events->color_set == 2)
	{
		color->start = THREE_END;
		color->end = THREE_MIDDLE;
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
}

static int		rgb_color(t_fractol *fractol, int iterations)
{
	double	percentage;
	t_color color;
	int		red;
	int		green;
	int		blue;

	color = fractol->color;
	if (iterations < fractol->max_iterations / 4)
	{
		percentage = iterations / (double)(fractol->max_iterations / 4);
		set_color_to_mid(&color, &fractol->event);
	}
	else
	{
		percentage = iterations / (double)fractol->max_iterations;
		set_color_to_end(&color, &fractol->event);
	}
	red = get_bit_value(\
		(color.start >> 16) & 0xFF, (color.end >> 16) & 0xFF, percentage);
	green = get_bit_value(\
		(color.start >> 8) & 0xFF, (color.end >> 8) & 0xFF, percentage);
	blue = get_bit_value(color.start & 0xFF, color.end & 0xFF, percentage);
	return (red << 16 | green << 8 | blue);
}

int				get_color(t_fractol *fractol, int iteration)
{
	if (fractol->event.color_grade == 1)
		return (hsv_color(iteration));
	return (rgb_color(fractol, iteration));
}
