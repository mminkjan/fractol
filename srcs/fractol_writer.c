/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_writer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 16:58:01 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 13:42:45 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

static void	fractol_calculate(t_fractol *fractol, int x, int y)
{
	double		iteration;
	size_t		index;
	t_numbers	*number;

	number = fractol->numbers;
	complex_calculation(fractol, number, x, y);
	iteration = 0.0;
	while (number->old_real * number->old_real + \
	number->old_i * number->old_i <= 4 && iteration < fractol->max_iterations)
	{
		number->new_real = number->old_real * number->old_real - \
			number->old_i * number->new_i + number->c_real;
		number->new_i = 2 * number->old_real * number->old_i + number->c_i;
		number->old_real = number->new_real;
		number->old_i = number->new_i;
		iteration++;
	}
	if (iteration != fractol->max_iterations)
	{
		index = y * WIDTH + x;
		fractol->color.color_ppixel[index] = get_color(fractol, iteration);
	}
}

static void	*render_thread(void *t)
{
	int x;
	int y;
	t_thread *thread;

	thread = (t_thread*)t;
	y = HEIGHT / THREADS * thread->id;
	while (y < HEIGHT / THREADS * (thread->id + 1))
	{
		x = 0;
		while (x < WIDTH)
		{
			fractol_calculate(thread->fractol, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

static void	fractol_thread(t_fractol *fractol)
{
	size_t		thread_count;
	t_render	*render;

	render = fractol->render;
	thread_count = 0;
	while (thread_count < THREADS)
	{
		render->args[thread_count].id = thread_count;
		render->args[thread_count].fractol = fractol;
		pthread_create(render->thread + thread_count, NULL, render_thread, &(render->args[thread_count]));
		thread_count++;
	}
	thread_count = 0;
	while (thread_count < THREADS)
	{
		pthread_join(render->thread[thread_count], NULL);
		thread_count++;
	}
	draw_fractol(fractol);
}

int		fractol_writer(t_fractol *fractol)
{
	mlx_key_hook(fractol->window_ptr, key_press, fractol);
	mlx_hook(fractol->window_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->window_ptr, 6, 0, mouse_move, fractol);
	mlx_hook(fractol->window_ptr, 5, 0, mouse_release, fractol);
	fractol_thread(fractol);
	return (0);
}
