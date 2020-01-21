/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:02 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/21 18:55:29 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		color_key(int key, t_fractol *fractol)
{
	if (key == SPACE)
	{
		if (fractol->event.color_set == 0)
			fractol->event.color_set++;
		else if (fractol->event.color_set == 1)
			fractol->event.color_set++;
		else if (fractol->event.color_set == 2)
			fractol->event.color_set = 0;
	}
	if (key == LINEAR)
	{
		if (fractol->event.color_grade == 0)
			fractol->event.color_grade = 1;
		else
			fractol->event.color_grade = 0;
		fractol_writer(fractol);
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
		}
		if (fractol->type == 3)
		{
			fractol->numbers->c_real = 0.3;
			fractol->numbers->c_i = -0.01;
		}
		fractol->max_iterations = 256;
		fractol->color.saturation = 100;
		fractol->color.value = 100;
		fractol->event.zoom = 1.1;
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
		fractol->type = 2;
	if (key == THREE)
	{
		fractol->type = 3;
		fractol->numbers->c_real = 0.3;
		fractol->numbers->c_i = -0.01;
	}
}

static void		iteration_escape_key(int key, t_fractol *fractol)
{
	if (key == INCREASE_ITERATIONS)
		fractol->max_iterations *= 2;
	if (key == DECREASE_ITERATIONS)
		if (fractol->max_iterations > 10)
			fractol->max_iterations /= 2;
	if (key == INCREASE_SATURATION)
		if (fractol->color.saturation <= 250)
			fractol->color.saturation += 0.5;
	if (key == DECREASE_SATURATION)
		if (fractol->color.saturation >= 5)
			fractol->color.saturation -= 0.5;
	if (key == INCREASE_VALUE)
		if (fractol->color.value <= 250)
			fractol->color.value += 0.5;
	if (key == DECREASE_VALUE)
		if (fractol->color.value >= 5)
			fractol->color.value += 0.5;
	if (key == ESC)
	{
		ft_bzero(fractol, sizeof(fractol));
		free(fractol);
		exit(0);
	}
}

int				key_press(int key, t_fractol *fractol)
{
	iteration_escape_key(key, fractol);
	color_key(key, fractol);
	fractol_key(key, fractol);
	reset_key(key, fractol);
	fractol_writer(fractol);
	return (0);
}
