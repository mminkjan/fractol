/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_color.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:35:13 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/16 18:48:18 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int			get_bit_value(int start, int end, double percentage)
{
	double start_1;
	double end_1;
	int		result;

	start_1 = (1.0 - percentage) * start;
	end_1 = percentage * end;
	result = (int)(start_1 + end_1);
	return (result);
	// return ((int)((1 - percentage) * start + percentage * end));
}

static void			set_color_to_end(t_color *color, t_events *events)
{
	(void)events;
	// if (events->color_middle == 0)
	// 	color->start = ONE_MIDDLE;
	// if (events->color_middle == 1)
	// 	color->start = TWO_MIDDLE;
	// if (events->color_middle == 2)
	// 	color->start = THREE_MIDDLE;
	// if (events->color_end == 0)
	// 	color->start = ONE_END;
	// if (events->color_end == 1)
	// 	color->start = TWO_END;
	// if (events->color_end == 2)
	// 	color->start = THREE_END;
	// else
	// {
		color->start = DEFAULT_MIDDLE;
		color->end = DEFAULT_START;
	// }
}

static void			set_color_to_mid(t_color *color, t_events *events)
{
	(void)events;
	// if (events->color_start == 0)
	// 	color->start = ONE_START;
	// if (events->color_start == 1)
	// 	color->start = TWO_START;
	// if (events->color_start == 2)
	// 	color->start = THREE_START;
	// if (events->color_middle == 0)
	// 	color->end = ONE_MIDDLE;
	// if (events->color_middle == 1)
	// 	color->end = TWO_MIDDLE;
	// if (events->color_middle == 2)
	// 	color->end = THREE_MIDDLE;
	// else
	// {
		color->start = DEFAULT_START;
		color->end = DEFAULT_MIDDLE;
	// }
}

int		get_color(t_fractol *fractol, int iteration)
{
	double	percentage;
	t_color color;
	int		red;
	int		green;
	int		blue;

	color = fractol->color;
	if (iteration < MAX_ITERATIONS / 4)
	{
		percentage = iteration / (float)(MAX_ITERATIONS / 4);
		set_color_to_mid(&color, &fractol->event);
	}
	else
	{
		percentage = ((iteration - (float)(MAX_ITERATIONS / 4)) / (float)(MAX_ITERATIONS / 4)); 
		set_color_to_end(&color, &fractol->event);
	}
	red = get_bit_value((color.start >> 16) & 0xFF, (color.end >> 16) & 0xFF, percentage);
	green = get_bit_value((color.start >> 8) & 0xFF, (color.end >> 8) & 0xFF, percentage); 
	blue = get_bit_value(color.start & 0xFF, color.end & 0xFF, percentage);
	return (red << 16 | green << 8 | blue);
}
