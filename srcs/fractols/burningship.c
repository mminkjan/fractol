/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 11:32:45 by JessicaSmit    #+#    #+#                */
/*   Updated: 2020/02/01 14:18:22 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void		complex_calculation(t_fractol *fractol,
					t_numbers *nb, int x, int y)
{
	t_events event;

	event = fractol->event;
	nb->c_real = \
		((x - WIDTH / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_x;
	nb->c_i = \
		((y - HEIGHT / 2.0) * 4.0) / (WIDTH * event.zoom) + event.mouse_y;
	nb->old_real = 0;
	nb->old_i = 0;
}

t_pixel			burningship_fractol(t_fractol *fractol, int x, int y)
{
	t_numbers	nb;
	int			iterations;

	complex_calculation(fractol, &nb, x, y);
	iterations = 0;
	while (nb.old_real * nb.old_real + nb.old_i * nb.old_i < 4 \
		&& iterations < fractol->max_iterations)
	{
		nb.new_real = fabs(nb.old_real * nb.old_real - \
			nb.old_i * nb.new_i + nb.c_real);
		nb.new_i = fabs(2 * nb.old_real * nb.old_i + nb.c_i);
		nb.old_real = nb.new_real;
		nb.old_i = nb.new_i;
		iterations++;
	}
	return ((t_pixel){{nb.old_real, nb.old_i}, iterations});
}
