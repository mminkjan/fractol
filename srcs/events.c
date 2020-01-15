/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:02 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/15 16:53:29 by jesmith       ########   odam.nl         */
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
	double	diff_x;
	double	diff_y;
	double	start_pan_x;
	double	start_pan_y;

	if ((fractol->event.hold_x == 0 && fractol->event.hold_y == 0) || fractol->event.hold_x != x || fractol->event.hold_y != y)
	{
		fractol->event.hold_x = x;
		fractol->event.hold_y = y;
	}
	start_pan_x = fractol->event.hold_x;
	start_pan_y = fractol->event.hold_y;
	if (key == SCROLL_UP && fractol->event.zoom > 0.5)
	{
		fractol->event.zoom -= 0.5;
	}
	if (key == SCROLL_DOWN)
	{
		fractol->event.zoom += 0.5;
		diff_x = fractol->event.hold_x - start_pan_x * fractol->event.zoom;
		diff_y = fractol->event.hold_y - start_pan_y * fractol->event.zoom;
		if (diff_x != x && diff_y != y)
		{
			fractol->event.mouse_x -= diff_x - x; //fractol->points->x + (diff_x * 0.02);
			fractol->event.mouse_y -= diff_y - y; //fractol->points->y + (diff_y * 0.02);
			start_pan_x = fractol->event.mouse_x;
			start_pan_y = fractol->event.mouse_y;
		}
		if (diff_x == x && diff_y == y)
		{
			fractol->event.hold_x = 0;
			fractol->event.hold_y = 0;
		}

	}
	if (key == MOUSE_PRESS)
		fractol->event.mouse_press = 1;
	
	return (0);
}

// int		mouse_move(int key, int x, int y, t_fractol *fractol)
// {

// }

int		mouse_release(int key, int x, int y, t_fractol *fractol)
{
	x = 0;
	y = 0;
	if (key == MOUSE_PRESS)
		fractol->event.mouse_press = 0;
	return (0);
}
