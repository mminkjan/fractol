/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:20:30 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/27 13:54:25 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				check_input(t_fractol *fractol, char *argv)
{
	if (ft_strcmp("Julia", argv) == 0)
	{
		fractol->argv = "Julia";
		fractol->type = 1;
		fractol->c_real = -0.7;
		fractol->c_i = 0.27015;
	}
	else if (ft_strcmp("Mandelbrot", argv) == 0)
	{
		fractol->argv = "Mandelbrot";
		fractol->type = 2;
	}
	else if (ft_strcmp("Mandelbar", argv) == 0)
	{
		fractol->argv = "Mandelbar";
		fractol->type = 3;
	}
	else if (ft_strcmp("BurningShip", argv) == 0)
	{
		fractol->argv = "BurningShip";
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
	fractol->pixel = (t_pixel*)ft_memalloc(sizeof(t_pixel) * WIDTH * HEIGHT);
	if (fractol->pixel == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	fractol->event.zoom = 1.1;
	fractol->max_iterations = 190;
	return (fractol);
}

void				fractol_exit(char *str, t_fractol *fractol)
{
	ft_putstr(str);
	if (fractol != NULL && fractol->pixel != NULL)
	{
		ft_bzero(fractol->pixel, sizeof(t_pixel));
		free(fractol->pixel);
	}
	if (fractol != NULL)
	{
		ft_bzero(fractol, sizeof(t_fractol));
		free(fractol);
	}
	exit(0);
}
