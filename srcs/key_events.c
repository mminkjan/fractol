/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:02 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/01 13:52:23 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		switch_fractol_bonus(int key, t_fractol *fractol)
{
	if (key == THREE)
	{
		fractol->type = 3;
		fractol->argv = "Mandelbar";
		fractol->selector = &mandelbar_fractol;
	}
	else if (key == FOUR)
	{
		fractol->type = 4;
		fractol->argv = "BurningShip";
		fractol->selector = &burningship_fractol;
	}
}

static void		switch_fractol(int key, t_fractol *fractol)
{
	if (key == ONE)
	{
		fractol->type = 1;
		fractol->argv = "Julia";
		fractol->selector = &julia_fractol;
		fractol->c_real = -0.7;
		fractol->c_i = 0.27015;
	}
	else if (key == TWO)
	{
		fractol->type = 2;
		fractol->argv = "Mandelbrot";
		fractol->selector = &mandelbrot_fractol;
	}
	else
		switch_fractol_bonus(key, fractol);
	reset_key(fractol);
}

static void		fractol_key(int key, t_fractol *fractol)
{
	if (key == ONE || key == TWO || key == THREE || key == FOUR)
	{
		switch_fractol(key, fractol);
		mlx_clear_window(fractol->mlx_ptr, fractol->window_ptr);
		print_interface(fractol);
	}
	else if (key == ESC)
	{
		ft_bzero(fractol, sizeof(fractol));
		free(fractol);
		exit(EXIT_SUCCESS);
	}
}

static void		alteration_keys(int key, t_fractol *fractol)
{
	if (key == INCREASE_ITERATIONS && fractol->max_iterations < 760)
		fractol->max_iterations *= 1.5;
	else if (key == DECREASE_ITERATIONS && fractol->max_iterations > 10)
		fractol->max_iterations /= 1.5;
	else if (key == ARROW_DOWN)
		fractol->event.mouse_y -= 0.5 / fractol->event.zoom;
	else if (key == ARROW_UP)
		fractol->event.mouse_y += 0.5 / fractol->event.zoom;
	else if (key == ARROW_RIGHT)
		fractol->event.mouse_x -= 0.5 / fractol->event.zoom;
	else if (key == ARROW_LEFT)
		fractol->event.mouse_x += 0.5 / fractol->event.zoom;
	else if (key == FREEZE)
	{
		if (fractol->event.freeze == 0)
			fractol->event.freeze = 1;
		else
			fractol->event.freeze = 0;
	}
}

int				key_press(int key, t_fractol *fractol)
{
	alteration_keys(key, fractol);
	fractol_key(key, fractol);
	color_key(key, fractol);
	if (key == RESET)
		reset_key(fractol);
	return (0);
}
