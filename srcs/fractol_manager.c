/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_manager.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:11:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/22 19:48:30 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

static void		constant_calculation(t_fractol *fractol,
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

static void		set_calculation(t_fractol *fractol,
					t_numbers *nb, int x, int y)
{
	int			iterations;
	int			color;

	constant_calculation(fractol, nb, x, y);
	iterations = 0;
	while (nb->old_real * nb->old_real + \
	nb->old_i * nb->old_i <= 4 && iterations < fractol->max_iterations)
	{
		nb->new_real = nb->old_real * nb->old_real - \
			nb->old_i * nb->new_i + nb->c_real;
		nb->new_i = fractol->two * nb->old_real * nb->old_i + nb->c_i;
		nb->old_real = nb->new_real;
		nb->old_i = nb->new_i;
		iterations++;
	}
	if (iterations != fractol->max_iterations)
	{
		color = get_color(fractol, iterations);
		put_pixel(fractol, color, x, y);
	}
}

static void		draw_fractol(t_fractol *fractol)
{
	t_events	events;
	t_numbers	*nb;
	int			x;
	int			y;

	y = 0;
	events = fractol->event;
	nb = fractol->numbers;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_calculation(fractol, nb, x, y);
			x++;
		}
		y++;
	}
	y = 0;
}

int				fractol_manager(t_fractol *fractol)
{
	mlx_key_hook(fractol->window_ptr, key_press, fractol);
	mlx_hook(fractol->window_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->window_ptr, 6, 0, mouse_move, fractol);
	mlx_hook(fractol->window_ptr, 5, 0, mouse_release, fractol);
	draw_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr,\
		fractol->image_ptr, 400, 0);
	ft_bzero(fractol->addr_str, (fractol->bits_ppixel / 8) * WIDTH * HEIGHT);
	return (0);
}
