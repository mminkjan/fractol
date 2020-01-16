/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:02 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/16 20:37:01 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		color_key(int key, t_events *event)
{
	if (key == ONE)
	{
		event->color_start++;
		if (event->color_start == 3)
			event->color_start = 0;
	}
	if (key == TWO)
	{
		event->color_middle++;
		if (event->color_middle == 3)
			event->color_middle = 0;
	}
	if (key == THREE)
	{
		event->color_end++;
		if (event->color_end == 3)
			event->color_end = 0;
	}
}

int		key_press(int key, t_fractol *fractol)
{
	if (key == ESC)
	{
		ft_bzero(fractol, sizeof(fractol));
		free(fractol);
		exit(0);
	}
	color_key(key, &fractol->event);
	return (0);
}

int		mouse_press(int key, int x, int y, t_fractol *fractol)
{
	// x = 0;
	// y = 0;
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

int		mouse_move(int x, int y, t_fractol *fractol)
{
	if (fractol->event.mouse_press == 1)
	{
		fractol->event.mouse_x += 0.001 * (fractol->event.hold_x - x) / fractol->event.zoom;
		fractol->event.mouse_y += 0.001 * (fractol->event.hold_y - y) / fractol->event.zoom;
		printf("move: %f, %f\n", fractol->event.mouse_x, fractol->event.mouse_y);
	}
	return (0);
}

int		mouse_release(int key, int x, int y, t_fractol *fractol)
{
	x = 0;
	y = 0;
	if (key == MOUSE_PRESS)
		fractol->event.mouse_press = 0;
	return (0);
}
