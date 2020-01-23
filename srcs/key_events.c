/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:02 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/23 19:47:33 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		color_key(int key, t_fractol *fractol)
{
	if (key == SPACE)
	{
		fractol->event.color_grade = 0;
		if (fractol->event.color_set == -1)
			fractol->event.color_set++;
		else if (fractol->event.color_set == 0)
			fractol->event.color_set++;
		else if (fractol->event.color_set == 1)
			fractol->event.color_set++;
		else if (fractol->event.color_set == 2)
		{
			fractol->event.color_grade = 1;
			fractol->event.color_set = -1;
		}
	}
}

static void		reset_key(int key, t_fractol *fractol)
{
	if (key == RESET)
	{
		if (fractol->type == 1)
		{
			fractol->numbers->c_real = -0.7;
			fractol->numbers->c_i = 0.27015;
			fractol->two = 2;
		}
		if (fractol->type == 2)
			fractol->two = 2;
		if (fractol->type == 3)
			fractol->two = -2;
		fractol->max_iterations = 190;
		fractol->event.zoom = 1.1;
		fractol->event.color_set = 0;
		fractol->event.color_grade = 0;
		fractol->event.mouse_x = 0;
		fractol->event.mouse_y = 0;
	}
}

static void		fractol_key(int key, t_fractol *fractol)
{
	if (key == ONE)
	{
		fractol->type = 1;
		fractol->numbers->c_real = -0.7;
		fractol->numbers->c_i = 0.27015;
	}
	if (key == TWO)
	{
		fractol->type = 2;
		fractol->two = 2;
	}
	if (key == THREE)
	{
		fractol->type = 3;
		fractol->two = -2;
	}
	if (key == ESC)
	{
		ft_bzero(fractol, sizeof(fractol));
		free(fractol);
		exit(EXIT_SUCCESS);
	}
}

static void		alteration_key(int key, t_fractol *fractol)
{
	if (key == INCREASE_ITERATIONS && fractol->max_iterations < 780)
		fractol->max_iterations *= 1.5;
	if (key == DECREASE_ITERATIONS && fractol->max_iterations > 10)
		fractol->max_iterations /= 1.5;
	if (key == ARROW_UP)
		fractol->event.mouse_y += 0.5 / fractol->event.zoom;
	if (key == ARROW_DOWN)
		fractol->event.mouse_y -= 0.5 / fractol->event.zoom;
	if (key == ARROW_RIGHT)
		fractol->event.mouse_x -= 0.5 / fractol->event.zoom;
	if (key == ARROW_LEFT)
		fractol->event.mouse_x += 0.5 / fractol->event.zoom;
	if (key == FREEZE)
	{
		if (fractol->event.freeze == 1)
			fractol->event.freeze = 0;
		else
			fractol->event.freeze = 1;
	}
}

int				key_press(int key, t_fractol *fractol)
{
	alteration_key(key, fractol);
	color_key(key, fractol);
	fractol_key(key, fractol);
	reset_key(key, fractol);
	fractol_writer(fractol);
	return (0);
}
