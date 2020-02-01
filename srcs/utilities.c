/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:20:30 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/01 14:26:53 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	bonus_fractols(t_fractol *fractol, char *argv)
{
	if (ft_strcmp("Mandelbar", argv) == 0)
	{
		fractol->argv = "Mandelbar";
		fractol->selector = &mandelbar_fractol;
		fractol->type = 3;
		return (0);
	}
	else if (ft_strcmp("BurningShip", argv) == 0)
	{
		fractol->argv = "BurningShip";
		fractol->selector = &burningship_fractol;
		fractol->type = 4;
		return (0);
	}
	return (1);
}

void		check_input(t_fractol *fractol, char *argv)
{
	if (ft_strcmp("Julia", argv) == 0)
	{
		fractol->argv = "Julia";
		fractol->selector = &julia_fractol;
		fractol->type = 1;
		fractol->c_real = -0.7;
		fractol->c_i = 0.27015;
	}
	else if (ft_strcmp("Mandelbrot", argv) == 0)
	{
		fractol->argv = "Mandelbrot";
		fractol->selector = &mandelbrot_fractol;
		fractol->type = 2;
	}
	else if (bonus_fractols(fractol, argv) == 1)
		fractol_exit(USAGE_ERR, fractol);
}

t_fractol	*fractol_init(void)
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
