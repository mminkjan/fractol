/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 11:32:40 by JessicaSmit    #+#    #+#                */
/*   Updated: 2020/01/27 12:36:55 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void		complex_calculation(t_fractol *fractol, int x, int y,
					t_numbers *nb)
{
	t_events event;

	event = fractol->event;
	nb->c_real = fractol->c_real;
	nb->c_i = fractol->c_i;
	nb->new_real = \
		((x - WIDTH / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_x;
	nb->new_i = \
		((y - HEIGHT / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_y;
	nb->old_real = nb->new_real;
	nb->old_i = nb->new_i;
}

void			julia_fractol(t_fractol *fractol, int x, int y)
{
	int			iterations;
	t_numbers	nb;

	complex_calculation(fractol, x, y, &nb);
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
		put_pixel(fractol, x, y, get_color(fractol, iterations));
}
