/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_key_events.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:03:14 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/23 21:35:10 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		switch_fractol(int key, t_fractol *fractol)
{
	if (key == ONE)
	{
		fractol->argv = "Julia";
		fractol->selector = &julia_fractol;
		fractol->c_real = -0.7;
		fractol->c_i = 0.27015;
	}
	else if (key == TWO)
	{
		fractol->argv = "Mandelbrot";
		fractol->selector = &mandelbrot_fractol;
	}
	else if (key == THREE)
	{
		fractol->argv = "Mandelbar";
		fractol->selector = &mandelbar_fractol;
	}
	else if (key == FOUR)
	{
		fractol->argv = "BurningShip";
		fractol->selector = &burningship_fractol;
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
		exit_success(fractol);

}
