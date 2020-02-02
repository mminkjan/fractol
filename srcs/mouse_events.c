/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_events.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 19:20:35 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/02 09:11:08 by jessicasmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		mouse_move_julia(int y, t_fractol *fractol)
{
	if (y < HEIGHT / 2)
	{
		fractol->c_real += 0.01 / fractol->event.zoom;
		fractol->c_i += 0.02 / fractol->event.zoom;
		fractol_writer(fractol);
	}
	else if (y > HEIGHT / 2)
	{
		fractol->c_real -= 0.01 / fractol->event.zoom;
		fractol->c_i -= 0.02 / fractol->event.zoom;
		fractol_writer(fractol);
	}
}

int				mouse_move(int x, int y, t_fractol *fractol)
{
	if (fractol->event.mouse_press == 1)
	{
		fractol->event.mouse_x += \
			(fractol->event.hold_x - x) / (WIDTH * fractol->event.zoom) * 4;
		fractol->event.mouse_y += \
			(fractol->event.hold_y - y) / (HEIGHT * fractol->event.zoom) * 4;
		fractol->event.hold_x = x;
		fractol->event.hold_y = y;
		fractol_writer(fractol);
	}
	else if (fractol->event.mouse_press == 0 && \
		fractol->selector == &julia_fractol && fractol->event.freeze == 0)
		mouse_move_julia(y, fractol);
	return (0);
}

int				mouse_press(int key, int x, int y, t_fractol *fractol)
{
	if (key == SCROLL_UP && fractol->event.zoom > 1.1)
	{
		fractol->event.zoom /= 1.1;
		fractol_writer(fractol);
	}
	else if (key == SCROLL_DOWN)
	{
		fractol->event.zoom *= 1.1;
		fractol_writer(fractol);
	}
	else if (key == MOUSE_PRESS)
	{
		fractol->event.mouse_press = 1;
		fractol->event.hold_x = x;
		fractol->event.hold_y = y;
	}
	return (0);
}

int				mouse_release(int key, int x, int y, t_fractol *fractol)
{
	x = 0;
	y = 0;
	if (key == MOUSE_PRESS)
		fractol->event.mouse_press = 0;
	fractol_writer(fractol);
	return (0);
}

int				close_window(t_fractol *fractol)
{
	ft_bzero(fractol->pixel, sizeof(t_pixel));
	free(fractol->pixel);
	ft_bzero(fractol, sizeof(t_fractol));
	free(fractol);
	exit(0);
}
