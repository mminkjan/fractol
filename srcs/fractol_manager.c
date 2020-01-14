/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_manager.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:11:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/14 18:53:48 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		put_pixel(t_fractol *fractol)
{
	size_t		index;
	t_points	*points;

	points = fractol->points;
	if (points->x >= 0 && points->x < WIDTH && \
			points->y >= 0 && points->y < HEIGHT)
	{
		index = ((int)points->y * fractol->size_line) + \
			((int)points->x * fractol->bits_ppixel / 8);
		fractol->addr_str[index] = fractol->color;
		index++;
		fractol->addr_str[index] = fractol->color >> 8;
		index++;
		fractol->addr_str[index] = fractol->color >> 16;
	}
}

static int			get_bit_value(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		get_percentage(int iteration)
{
	int placement;
	int	distance;

	if (iteration < 100)
	{
		placement = iteration;
		distance = 100;
	}
	else
	{
		placement = iteration - 100;
		distance = MAX_ITERATIONS - 100;
	}
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_color(t_fractol *fractol, int iteration)
{
	double percentage;
	int	red;
	int green;
	int blue;

	if (iteration < 40)
	{
		fractol->color1 = 0x0000ff;
		fractol->color2 = 0xff00f4;
	}
	else
	{
		fractol->color1 = 0xff00f4;
		fractol->color2 = 0xffffff;
	}
	percentage = iteration / (float)MAX_ITERATIONS;
	percentage = get_percentage(iteration);
	red = get_bit_value((fractol->color1 >> 16) & 0xFF, (fractol->color2 >> 16) & 0xFF, percentage);
	green = get_bit_value((fractol->color1 >> 8) & 0xFF, (fractol->color2 >> 8) & 0xFF, percentage); 
	blue = get_bit_value(fractol->color1 & 0xFF, fractol->color2 & 0xFF, percentage);
	return (red << 16 | green << 8 | blue);
}

static void		constant_calculation(t_fractol *fractol, t_numbers *number, t_points *points)
{
	if (fractol->type == 1 || fractol->type == 3)
	{
		number->old_real = (points->x - WIDTH / 2.0) * 4.0 / WIDTH;
		number->old_i = (points->y - HEIGHT / 2.0) * 4.0 / WIDTH;
	}
	else if (fractol->type == 2)
	{
		// number->c_real = -1 + (points->x / WIDTH) * (1 - -1);
		// number->c_i = -1 + (points->y / HEIGHT) * (1 - -1);
		number->c_real = (points->x - WIDTH / 2.0) * 4.0 / WIDTH;
		number->c_i = (points->y - HEIGHT / 2.0) * 4.0 / WIDTH;
		number->old_real = 0;
		number->old_i = 0;
	}
}

static void		draw_fractol(t_fractol *fractol)
{
	t_points	*points;
	t_events	events;
	t_numbers	*number;
	int		iteration;

	points = fractol->points;
	events = fractol->event;
	number = fractol->numbers;
	while (points->y < HEIGHT)
	{
		points->x = 0;
		// iteration = 0;
		while (points->x < WIDTH)
		{
			// int z = 0;
			// int complex;
			// constant_calculation(fractol, number, points);
			// complex = number->c_real * number->c_real + number->c_i * number->c_i;
    		// while (abs(z) <= 2 && iteration < MAX_ITERATIONS)
			// {
       		// 	z = z * z + complex;
       		// 	iteration++;
			// }
			constant_calculation(fractol, number, points);
       		iteration = 0;
			while (number->old_real * number->old_real + number->old_i * number->old_i <= 4 && iteration < MAX_ITERATIONS) 
			{
				number->new_real = number->old_real * number->old_real -  number->old_i * number->new_i + number->c_real;
				number->new_i = 2 * number->old_real * number->old_i + number->c_i;
				number->old_real = number->new_real;
				number->old_i = number->new_i;
				iteration++;
			}
			if (iteration != MAX_ITERATIONS)
			{
				fractol->color = get_color(fractol, iteration);
				put_pixel(fractol);
			}
			points->x++;
		}
		points->y++;
	}
}

int				fractol_manager(t_fractol *fractol)
{
	mlx_key_hook(fractol->window_ptr, key_press, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_scroll, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_press, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_release, fractol);
	draw_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr,\
		fractol->image_ptr, 0, 0);
	// ft_bzero(fractol->addr_str, (fractol->bits_ppixel / 8) * WIDTH * HEIGHT);
	return (0);
}
