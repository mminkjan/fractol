/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 11:32:40 by JessicaSmit    #+#    #+#                */
/*   Updated: 2020/01/26 15:31:55 by jessicasmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void		complex_calculation(t_fractol *fractol,
					t_numbers *nb, int x, int y)
{
	t_events event;

	event = fractol->event;
	nb->c_real = fractol->c_real;
	nb->c_i = fractol->c_i;
    nb->new_real = ((x - WIDTH / 2.0) * 4.0) \
        / (WIDTH * event.zoom) + event.mouse_x;
    nb->new_i = ((y - HEIGHT / 2.0) * 4.0) \
        / (WIDTH * event.zoom) + event.mouse_y;
    nb->old_real = nb->new_real;
    nb->old_i = nb->new_i;
}

void		    julia_fractol(t_fractol *fractol, int x, int y)
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