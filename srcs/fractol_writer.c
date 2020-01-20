/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_writer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 16:58:01 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 23:00:16 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdint.h>

static void		complex_calculation(t_fractol *fractol,
					t_numbers *number, int x, int y)
{
	t_events event;

	event = fractol->event;
	if (fractol->type == 1 || fractol->type == 3)
	{
		number->new_real = ((x - WIDTH / 2.0) * 4.0) \
			/ (WIDTH * event.zoom) + event.mouse_x;
		number->new_i = ((y - HEIGHT / 2.0) * 4.0) \
			/ (WIDTH * event.zoom) + event.mouse_y;
		number->old_real = number->new_real;
		number->old_i = number->new_i;
	}
	else if (fractol->type == 2)
	{
		number->c_real = ((x - WIDTH / 2.0) * 4.0)  \
			/ (WIDTH * event.zoom) + event.mouse_x;
		number->c_i = ((y - HEIGHT / 2.0) * 4.0) \
			/ (WIDTH * event.zoom) + event.mouse_y;
		number->old_real = 0;
		number->old_i = 0;
	}
}

static t_pixel	fractol_calculate(t_fractol *fractol, int x, int y)
{
	t_numbers	*number;
	int			i;

	number = fractol->numbers;
	complex_calculation(fractol, number, x, y);
	i = 0;
	while (number->old_real * number->old_real + number->old_i * number->old_i < 4 && i < fractol->max_iterations)
	{
		number->new_real = number->old_real * number->old_real - \
			number->old_i * number->new_i + number->c_real;
		number->new_i = 2 * number->old_real * number->old_i + number->c_i;
		number->old_real = number->new_real;
		number->old_i = number->new_i;
		i++;
	}
	return ((t_pixel){{number->old_real, number->old_i}, i});
}

static void	*render_thread(void *t)
{
	int			x;
	int			y;
	t_thread	*thread;
	// int		index;
	
	thread = (t_thread*)t;
	y = HEIGHT / THREADS * thread->id;
	while (y < HEIGHT / THREADS * (thread->id + 1))
	{
		x = 0;
		while (x < WIDTH)
		{
			*(thread->fractol->pixel + y * WIDTH + x)  = fractol_calculate(thread->fractol, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

static void	fractol_thread(t_fractol *fractol)
{
	uintptr_t		thread_count;
	t_render	*render;

	render = &fractol->render;
	thread_count = 0;
	while (thread_count < THREADS)
	{
		render->args[thread_count].id = thread_count;
		render->args[thread_count].fractol = fractol;
		pthread_create(&render->threads[thread_count], NULL, render_thread, &(render->args[thread_count]));
		pthread_join(render->threads[thread_count], NULL);
		thread_count++;
	}
}

int		fractol_writer(t_fractol *fractol)
{
	fractol_thread(fractol);
	draw_fractol(fractol);
	ft_bzero(fractol->addr_str, fractol->size_line * fractol->bits_ppixel / 8);
	return (0);
}
