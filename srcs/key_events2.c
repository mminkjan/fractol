/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:03:14 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/27 14:07:57 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		switch_fractol(int key, t_fractol *fractol)
{
	if (key == ONE)
	{
		fractol->c_real = -0.7;
		fractol->c_i = 0.27015;
		fractol->argv = "Julia";
		fractol->type = 1;
	}
	if (key == TWO)
	{
		fractol->argv = "Mandelbrot";
		fractol->type = 2;
	}
	if (key == THREE)
	{
		fractol->argv = "Mandelbar";
		fractol->type = 3;
	}
	if (key == FOUR)
	{
		fractol->argv = "BurningShip";
		fractol->type = 4;
	}
}

void			fractol_key(int key, t_fractol *fractol)
{
	if (key == ONE || key == TWO || key == THREE || key == FOUR)
	{
		switch_fractol(key, fractol);
		mlx_clear_window(fractol->mlx_ptr, fractol->window_ptr);
		print_interface(fractol);
	}
	if (key == ESC)
	{
		ft_bzero(fractol, sizeof(fractol));
		free(fractol);
		exit(EXIT_SUCCESS);
	}
}
