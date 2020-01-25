/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 11:32:45 by JessicaSmit    #+#    #+#                */
/*   Updated: 2020/01/25 12:09:09 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"


static void		put_pixel(t_fractol *fractol, int color, int x, int y)
{
	size_t		index;

	if (x >= 0 && x < WIDTH && \
			y >= 0 && y < HEIGHT)
	{
		index = (y * fractol->size_line) + (x * fractol->bits_ppixel / 8);
		fractol->addr_str[index] = color;
		index++;
		fractol->addr_str[index] = color >> 8;
		index++;
		fractol->addr_str[index] = color >> 16;
	}
}

static void		complex_calculation(t_fractol *fractol,
					t_numbers *nb, int x, int y)
{
	t_events event;

	event = fractol->event;
	nb->c_real = ((x - WIDTH / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_x;
	nb->c_i = ((y - HEIGHT / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_y;
	nb->old_real = 0;
	nb->old_i = 0;
	fractol->c_real = nb->c_real;
    fractol->c_i = nb->c_i;
}

void		    burningship_fractol(t_fractol *fractol, int x, int y)
{
	int			iterations;
	int			color;
    t_numbers   nb;

	complex_calculation(fractol, &nb, x, y);
	iterations = 0;
	while (nb.old_real * nb.old_real + \
	nb.old_i * nb.old_i <= 4 && iterations < fractol->max_iterations)
	{
		nb.new_real = nb.old_real * nb.old_real - \
			nb.old_i * nb.old_i + nb.c_real;
		nb.new_i = 2 * nb.old_real * nb.old_i + nb.c_i;
		if (fractol->type == 4)
		{
			nb.new_real = fabs(nb.new_real);
			nb.new_i = fabs(nb.new_i);
		}
		nb.old_real = nb.new_real;
		nb.old_i = nb.new_i;
		iterations++;
	}
	if (iterations != fractol->max_iterations)
	{
		color = get_color(fractol, iterations);
		put_pixel(fractol, color, x, y);
	}
}
