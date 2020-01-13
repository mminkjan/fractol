/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_manager.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:11:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/13 15:16:03 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_fractol *fractol)
{
	size_t		index;
	t_points	points;

	points = fractol->points;
	if (points.x >= 0 && points.x < WIDTH && points.y >= 0 && points.y < HEIGHT)
	{
		index = ((int)points.y * fractol->size_line) + ((int)points.y * fractol->bits_ppixel / 8);
		fractol->addr_str[index] = fractol->color;
		index++;
		fractol->addr_str[index] = fractol->color;
		index++;
		fractol->addr_str[index] = fractol->color;
	}
}

void	draw_fractol(t_fractol *fractol)
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
			number->new_real = 1.5 * (points.x - WIDTH / 2) / (0.5 * events.zoom * WIDTH) + events.mouse_x; // for Mandelbrot this is equal to number->real_pixel
			number->new_i = (points.y - HEIGHT / 2) / (0.5 * events.zoom * HEIGHT) + events.mouse_y; // for Mandelbrot this is equal to number->i_pixel
			// for Mandelbrot new_real, new_i, old_i, old_real are set to 0.0;
			// printf("%f, %f\n", number->new_real, number->new_i);
			iteration = 0;
			while (iteration < MAX_ITERATIONS)
			{
				number->old_real = number->new_real;
				number->old_i = number->new_i;
				number->new_real = number->old_real * number->old_real - number->old_i * number->old_i + number->c_real; // + number->pixel_real
				number->new_i = 2 * number->old_real * number->old_i + number->c_i; // + number->pixel_i
				if ((number->new_real * number->new_real + number->new_i * number->new_i) > 4)
					break ;
				iteration++;
			}
			fractol->color = 0xffffff; //get_color(fractol);
			put_pixel(fractol);
			// printf("%f, %f\n", points.x, points.y);
			points.x++;
		}
		points.y++;
	}
}

void		draw_line(t_fractol *fractol)
{
	fractol->color = 0xffffff;
	while (fractol->points.x < WIDTH && fractol->points.y < HEIGHT)
	{
		put_pixel(fractol);
		fractol->points.x++;
		fractol->points.y++;
	}
}

// int		fractol_selection(fractol)
// {
// }

int		fractol_manager(t_fractol *fractol)
{
	mlx_key_hook(fractol->window_ptr, key_press, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_scroll, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_press, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_release, fractol);
	draw_fractol(fractol);
	// draw_line(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr,\
		fractol->image_ptr, 0, 0);
	// ft_bzero(fractol->addr_str, (fractol->bits_ppixel / 8) * WIDTH * HEIGHT);
	return (0);
}
