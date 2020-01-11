/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_manager.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:11:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/11 15:14:20 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol_draw(t_fractol *fractol)
{
	t_points	points;
	t_events	events;
	t_numbers	*number;
	size_t		iteration;

	points = fractol->points;
	events = fractol->event;
	number = fractol->numbers;
	iteration = 0;
	while (points.x < WIDTH && points.y < HEIGHT)
	{
		number->new_real = 1.5 * (points.x - WIDTH / 2) / (0.5 * events.zoom * WIDTH) + events.mouse_x; // for Mandelbrot this is equal to number->real_pixel
		number->new_i = (points.y - HEIGHT / 2) / (0.5 * events.zoom * HEIGHT) + events.mouse_y; // for Mandelbrot this is equal to number->i_pixel
		// for Mandelbrot new_real, new_i, old_i, old_real are set to 0.0; 
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
		fractol->color = get_color(fractol);
		put_pixel(fractol);
		points.x++;
		points.y++;
	}
}

int		fractol_selection(fractol)
{
	if (ft_strcmp)
}

int		fractol_manager(t_fractol *fractol)
{
	// mlx_key_hook(fractol->window_ptr, key_press, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_scroll, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_press, fractol);
	// mlx_key_hook(fractol->window_ptr, mouse_release, fractol);
	fractol_selector(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr,\
		fractol->image_ptr, 0, 0);
	ft_bzero(fractol->addr_str, (fractol->bits_ppixel / 8) * WIDTH * HEIGHT);
	return (0);
}
