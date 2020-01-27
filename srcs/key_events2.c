/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:03:14 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/27 19:51:40 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		switch_fractol(int key, t_fractol *fractol)
{
	if (key == ONE)
	{
		fractol->argv = "Julia";
		fractol->type = 1;
		fractol->c_real = -0.7;
		fractol->c_i = 0.27015;
	}
	else if (key == TWO)
	{
		fractol->argv = "Mandelbrot";
		fractol->type = 2;
	}
	else if (key == THREE)
	{
		fractol->argv = "Mandelbar";
		fractol->type = 3;
	}
	else if (key == FOUR)
	{
		fractol->argv = "BurningShip";
		fractol->type = 4;
	}
	reset_key(fractol);
}

void			fractol_key(int key, t_fractol *fractol)
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
