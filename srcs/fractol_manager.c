/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_manager.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:11:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/17 15:48:47 by mminkjan      ########   odam.nl         */
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
		fractol->addr_str[index] = fractol->rgb_color;
		index++;
		fractol->addr_str[index] = fractol->rgb_color >> 8;
		index++;
		fractol->addr_str[index] = fractol->rgb_color >> 16;
	}
}

static void		constant_calculation(t_fractol *fractol, t_numbers *number, t_points *points)
{
	t_events event;

	event = fractol->event;
	if (fractol->type == 1 || fractol->type == 3) // Julia
	{
		number->new_real = ((points->x - WIDTH / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_x;
		number->new_i = ((points->y - HEIGHT / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_y;
		number->old_real = number->new_real;
		number->old_i = number->new_i;
	}
	else if (fractol->type == 2) // Mandelbrot 
	{
		number->c_real = ((points->x - WIDTH / 2.0) * 4.0)  / (WIDTH * event.zoom) + event.mouse_x;
		number->c_i = ((points->y - HEIGHT / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_y;
		number->old_real = 0;
		number->old_i = 0;
	}
}

static void		draw_fractol(t_fractol *fractol)
{
	t_points	*points;
	t_events	events;
	t_numbers	*number;
	int			iteration;
	float		s_iteration;

	points = fractol->points;
	events = fractol->event;
	number = fractol->numbers;
	while (points->y < HEIGHT)
	{
		points->x = 0;
		while (points->x < WIDTH)
		{
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
				s_iteration = number->new_real + (number->new_i / 10);
				
				fractol->rgb_color = get_color(fractol, iteration);
				put_pixel(fractol);
			}
			points->x++;
		}
		points->y++;
	}
	points->y = 0;
}

int				fractol_manager(t_fractol *fractol)
{
	mlx_key_hook(fractol->window_ptr, key_press, fractol);
	mlx_hook(fractol->window_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->window_ptr, 6, 0, mouse_move, fractol);
	mlx_hook(fractol->window_ptr, 5, 0, mouse_release, fractol);
	draw_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr,\
		fractol->image_ptr, 0, 0);
	ft_bzero(fractol->addr_str, (fractol->bits_ppixel / 8) * WIDTH * HEIGHT);
	return (0);
}
