/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:03:14 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/24 15:08:42 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		switch_fractol(int key, t_fractol *fractol)
{
	fractol->two = 2;
	if (key == ONE)
	{
		fractol->type = 1;
		fractol->numbers->c_real = -0.7;
		fractol->numbers->c_i = 0.27015;
		fractol->argv = "Julia";
	}
	if (key == TWO || key == FOUR)
	{
		fractol->type = 2;
		fractol->argv = "Mandelbrot";
	}
	if (key == THREE)
	{
		fractol->type = 3;
		fractol->two = -2;
		fractol->argv = "Mandelbar";
	}
	if (key == FOUR)
	{
		fractol->type = 4;
		fractol->argv = "BurningShip";
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
		ft_bzero(fractol->numbers, sizeof(fractol->numbers));
		ft_bzero(fractol, sizeof(fractol));
		free(fractol);
		exit(EXIT_SUCCESS);
	}
}
