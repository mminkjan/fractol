/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_events.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 19:20:35 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/23 18:22:03 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				mouse_press(int key, int x, int y, t_fractol *fractol)
{
	if (key == SCROLL_UP && fractol->event.zoom > 1.1)
		fractol->event.zoom /= 1.1;
	if (key == SCROLL_DOWN)
		fractol->event.zoom *= 1.1;
	if (key == MOUSE_PRESS)
	{
		fractol->event.mouse_press = 1;
		fractol->event.hold_x = x;
		fractol->event.hold_y = y;
	}
	return (0);
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
	}
	if (fractol->event.mouse_press == 0 && \
		fractol->type == 1 && fractol->event.freeze == 0)
	{
		if (y < HEIGHT / 2)
		{
			fractol->numbers->c_real += 0.01;
			fractol->numbers->c_i += 0.02;
		}
		else if (y > HEIGHT / 2)
		{
			fractol->numbers->c_real -= 0.01;
			fractol->numbers->c_i -= 0.02;
		}
	}
	return (0);
}

int				mouse_release(int key, int x, int y, t_fractol *fractol)
{
	x = 0;
	y = 0;
	if (key == MOUSE_PRESS)
		fractol->event.mouse_press = 0;
	return (0);
}
