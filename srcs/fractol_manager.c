/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_manager.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:11:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/13 17:58:20 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_fractol *fractol, double x, double y)
{
	size_t		index;
	// t_points	points;

	// points = fractol->points;
	// printf("%f, %f\n", x, y);
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		index = ((int)y * fractol->size_line) + \
			((int)x * fractol->bits_ppixel / 8);
		fractol->addr_str[index] = fractol->color;
		index++;
		fractol->addr_str[index] = fractol->color;
		index++;
		fractol->addr_str[index] = fractol->color;
	}
}

static void		constant_calculation(t_fractol *fractol, t_numbers *number, t_points points)
{
	if (fractol->type == 1)
	{
		number->old_real = (points.x - WIDTH / 2.0) * 4.0 / WIDTH;
		number->old_i = (points.y - HEIGHT / 2.0) * 4.0 / WIDTH;
	}
	else if (fractol->type == 2)
	{
		number->c_real = (points.x - WIDTH / 2.0) * 4.0 / WIDTH;
		number->c_i = (points.y - HEIGHT / 2.0) * 4.0 / WIDTH;
		number->old_real = 0;
		number->old_i = 0;
	}
}

void			draw_fractol(t_fractol *fractol)
{
	t_points	points;
	t_events	events;
	t_numbers	*number;
	size_t		iteration;

	points = fractol->points;
	events = fractol->event;
	number = fractol->numbers;
	while (points.y < HEIGHT)
	{
		points.x = 0;
		while (points.x < WIDTH)
		{
			// printf("%f, %f\n", points.x, points.y);
			constant_calculation(fractol, number, points);
			// number->c_real = (points.x - WIDTH / 2.0) * 4.0 / WIDTH;
			// number->c_i = (points.y - HEIGHT / 2.0) * 4.0 / WIDTH;
			// number->old_real = 0;
			// number->old_i = 0;
       		iteration = 0;
			while (number->old_real * number->old_real + number->old_i * number->old_i <= 4 && iteration < MAX_ITERATIONS) 
			{
				number->new_real = number->old_real * number->old_real -  number->old_i * number->new_i + number->c_real;
				number->new_i = 2 * number->old_real * number->old_i + number->c_i;
				number->old_real = number->new_real;
				number->old_i = number->new_i;
				iteration++;
			}
			if (iteration < MAX_ITERATIONS)
			{
				// printf("here\n");
				fractol->color = 0xffffff;
				put_pixel(fractol, points.x, points.y);
			}
			points.x++;
		}
		points.y++;
	}
	// 	{
	// 		number->new_real = 1.5 * (points.x - WIDTH / 2) / (0.5 * WIDTH); // for Mandelbrot this is equal to number->real_pixel
	// 		number->new_i = (points.y - HEIGHT / 2) / (0.5 * HEIGHT); // for Mandelbrot this is equal to number->i_pixel
	// 		// for Mandelbrot new_real, new_i, old_i, old_real are set to 0.0;
	// 		iteration = 0;
	// 		while (iteration < MAX_ITERATIONS)
	// 		{
	// 			number->old_real = number->new_real;
	// 			number->old_i = number->new_i;
	// 			number->new_real = number->old_real * number->old_real - number->old_i * number->old_i + number->c_real; // + number->pixel_real
	// 			number->new_i = 2 * number->old_real * number->old_i + number->c_i; // + number->pixel_i
	// 			if ((number->new_real * number->new_real + number->new_i * number->new_i) > 4) // check if it is outside of radius 2, if it is, breaks and put color
	// 				break ;
	// 			iteration++;
	// 		}
	// 		fractol->color = 0xffffff; //get_color(fractol);
	// 		put_pixel(fractol);
	// 		// printf("%f, %f\n", points.x, points.y);
	// 		points.y++;
	// 	}
	// 	points.x++;
	// }
}

int		fractol_manager(t_fractol *fractol)
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
