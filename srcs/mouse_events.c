/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_events.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 19:20:35 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/18 19:21:10 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				mouse_press(int key, int x, int y, t_fractol *fractol)
{
	if (key == SCROLL_UP && fractol->event.zoom > 0.5)
		fractol->event.zoom -= 0.5;
	if (key == SCROLL_DOWN)
		fractol->event.zoom += 0.5;
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
		fractol->event.mouse_x += (fractol->event.hold_x - x) / WIDTH;
		fractol->event.mouse_y += (fractol->event.hold_y - y) / HEIGHT;
	}
	if (fractol->event.mouse_press == 0 && fractol->type == 1)
	{
		if (y < HEIGHT / 2)
		{
			fractol->numbers->c_real += 0.07;
			fractol->numbers->c_i += 0.07;
		}
		else if (y > HEIGHT / 2)
		{
			fractol->numbers->c_real -= 0.07;
			fractol->numbers->c_i -= 0.07;
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
