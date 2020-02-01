/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:03:14 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/01 13:53:46 by jesmith       ########   odam.nl         */
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
