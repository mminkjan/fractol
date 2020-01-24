/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:20:30 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/24 13:39:56 by mminkjan      ########   odam.nl         */
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

static void			set_julia(t_fractol *fractol, char *julia)
{
	fractol->argv = julia;
	fractol->numbers = numbers_init(fractol);
	fractol->type = 1;
	fractol->numbers->c_real = -0.7;
	fractol->numbers->c_i = 0.27015;
}

void				check_input(t_fractol *fractol, char **argv)
{
	fractol->two = 2;
	if (ft_strcmp("Julia", argv[1]) == 0)
		set_julia(fractol, argv[1]);
	else if (ft_strcmp("Mandelbrot", argv[1]) == 0)
	{
		fractol->argv = "Mandelbrot";
		fractol->numbers = numbers_init(fractol);
		fractol->type = 2;
	}
	else if (ft_strcmp("Mandelbar", argv[1]) == 0)
	{
		fractol->argv = "Mandelbar";
		fractol->numbers = numbers_init(fractol);
		fractol->type = 3;
		fractol->two = -2;
	}
	else if (ft_strcmp("BurningShip", argv[1]) == 0)
	{
		fractol->argv = "BurningShip";
		fractol->numbers = numbers_init(fractol);
		fractol->type = 4;
	}
	else
		fractol_exit(USAGE_ERR, fractol);
}

t_fractol			*fractol_init(void)
{
	t_fractol *fractol;

	fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol));
	if (fractol == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	fractol->event.zoom = 1.0;
	fractol->max_iterations = 150;
	return (fractol);
}

void				fractol_exit(char *str, t_fractol *fractol)
{
	ft_putstr(str);
	if (fractol != NULL && fractol->numbers != NULL)
	{
		ft_bzero(fractol->numbers, sizeof(t_numbers));
		free(fractol->numbers);
	}
	if (fractol != NULL)
	{
		ft_bzero(fractol, sizeof(t_fractol));
		free(fractol);
	}
	exit(0);
}
