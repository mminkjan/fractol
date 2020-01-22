/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_writer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 16:58:01 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/22 15:47:54 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		complex_calculation(t_fractol *fractol,
					t_numbers *nb, int x, int y)
{
	t_events event;

	event = fractol->event;
	if (fractol->type == 1)
	{
		nb->new_real = ((x - WIDTH / 2.0) * 4.0) \
			/ (WIDTH * event.zoom) + event.mouse_x;
		nb->new_i = ((y - HEIGHT / 2.0) * 4.0) \
			/ (WIDTH * event.zoom) + event.mouse_y;
		nb->old_real = nb->new_real;
		nb->old_i = nb->new_i;
	}
	else if (fractol->type == 2 || fractol->type == 3)
	{
		nb->c_real = ((x - WIDTH / 2.0) * 4.0)  \
			/ (WIDTH * event.zoom) + event.mouse_x;
		nb->c_i = ((y - HEIGHT / 2.0) * 4.0) \
			/ (WIDTH * event.zoom) + event.mouse_y;
		nb->old_real = 0;
		nb->old_i = 0;
	}
}

static t_pixel	fractol_calculate(t_fractol *fractol, int x, int y)
{
	t_numbers	*nb;
	int			iterations;

	nb = fractol->numbers;
	complex_calculation(fractol, nb, x, y);
	iterations = 0;
	while (nb->old_real * nb->old_real + nb->old_i * nb->old_i < 4 \
		&& iterations < fractol->max_iterations)
	{
		nb->new_real = nb->old_real * nb->old_real - \
			nb->old_i * nb->new_i + nb->c_real;
		nb->new_i = fractol->two * nb->old_real * nb->old_i + nb->c_i;
		nb->old_real = nb->new_real;
		nb->old_i = nb->new_i;
		iterations++;
	}
	return ((t_pixel){{nb->old_real, nb->old_i}, iterations});
}

static void		*render_thread(void *t)
{
	int			x;
	int			y;
	t_thread	*thread;

	thread = (t_thread*)t;
	y = HEIGHT / THREADS * thread->id;
	while (y < HEIGHT / THREADS * (thread->id + 1))
	{
		x = 0;
		while (x < WIDTH)
		{
			*(thread->fractol->pixel + y * WIDTH + x) = \
			fractol_calculate(thread->fractol, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

static void		fractol_thread(t_fractol *fractol)
{
	int			thread_count;
	t_render	*render;

	render = &fractol->render;
	thread_count = 0;
	while (thread_count < THREADS)
	{
		render->args[thread_count].id = thread_count;
		render->args[thread_count].fractol = fractol;
		pthread_create(&render->threads[thread_count], NULL, render_thread, \
			&(render->args[thread_count]));
		pthread_join(render->threads[thread_count], NULL);
		thread_count++;
	}
}

int				fractol_writer(t_fractol *fractol)
{
	fractol_thread(fractol);
	draw_fractol(fractol);
	ft_bzero(fractol->addr_str, fractol->size_line * fractol->bits_ppixel / 8);
	return (0);
}
