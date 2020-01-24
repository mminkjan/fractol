/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:15:10 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/24 14:52:55 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_numbers	*numbers_init(t_fractol *fractol)
{
	t_numbers *number;

	number = (t_numbers*)ft_memalloc(sizeof(t_numbers));
	if (number == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	return (number);
}

void				set_julia(t_fractol *fractol, char *julia)
{
	fractol->argv = julia;
	fractol->numbers = numbers_init(fractol);
	fractol->type = 1;
	fractol->numbers->c_real = -0.7;
	fractol->numbers->c_i = 0.27015;
}

void				check_input(t_fractol *fractol, char *argv)
{
	fractol->two = 2;
	if (ft_strcmp("Julia", argv) == 0)
		set_julia(fractol, argv);
	else if (ft_strcmp("Mandelbrot", argv) == 0)
	{
		fractol->argv = "Mandelbrot";
		fractol->numbers = numbers_init(fractol);
		fractol->type = 2;
	}
	else if (ft_strcmp("Mandelbar", argv) == 0)
	{
		fractol->argv = "Mandelbar";
		fractol->numbers = numbers_init(fractol);
		fractol->type = 3;
		fractol->two = -2;
	}
	else if (ft_strcmp("BurningShip", argv) == 0)
	{
		fractol->argv = "BurningShip";
		fractol->numbers = numbers_init(fractol);
		fractol->type = 4;
	}
	else
		fractol_exit(USAGE_ERR, fractol);
}
