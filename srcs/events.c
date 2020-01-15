/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:02 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/15 12:15:28 by jesmith       ########   odam.nl         */
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
	printf("key color: %d\n", fractol->event.color_start);
	return (0);
}

// int		mouse_scroll(int key)
// {

// }

// int		mouse_press(int key)
// {

// }

// int		mouse_release(int key)
// {

// }
