/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_color.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:35:13 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/14 19:27:04 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int			get_bit_value(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_fractol *fractol, int iteration)
{
	double percentage;
	int	red;
	int green;
	int blue;

	if (iteration < 40)
	{
		fractol->color1 = 0xffa500;
		fractol->color2 = 0xee3a6a;
		percentage = iteration / (float)40;
	}
	else
	{
		fractol->color1 = 0x72b2f3;
		fractol->color2 = 0xee3a6a;
		percentage = (iteration - 40) / (MAX_ITERATIONS - 40); 
	}
	// percentage = get_percentage(iteration);
	red = get_bit_value((fractol->color1 >> 16) & 0xFF, (fractol->color2 >> 16) & 0xFF, percentage);
	green = get_bit_value((fractol->color1 >> 8) & 0xFF, (fractol->color2 >> 8) & 0xFF, percentage); 
	blue = get_bit_value(fractol->color1 & 0xFF, fractol->color2 & 0xFF, percentage);
	return (red << 16 | green << 8 | blue);
}
