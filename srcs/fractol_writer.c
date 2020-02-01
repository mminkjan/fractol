/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_writer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 16:58:01 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/01 14:03:58 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
				thread->fractol->selector(thread->fractol, x, y);
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
		thread_count++;
	}
	thread_count = 0;
	while (thread_count < THREADS)
	{
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
