/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 13:20:39 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/24 13:43:31 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		color_key(int key, t_fractol *fractol)
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

void		reset_key(int key, t_fractol *fractol)
{
	if (key == RESET)
	{
		if (fractol->type == 1)
		{
			fractol->numbers->c_real = -0.7;
			fractol->numbers->c_i = 0.27015;
			fractol->two = 2;
		}
		if (fractol->type == 2 || fractol->type == 4)
			fractol->two = 2;
		if (fractol->type == 3)
			fractol->two = -2;
		fractol->max_iterations = 150;
		fractol->event.zoom = 1.1;
		fractol->event.color_grade = 0;
		fractol->event.color_set = 0;
		fractol->event.mouse_x = 0;
		fractol->event.mouse_y = 0;
		fractol->event.mouse_press = 0;
	}
}
