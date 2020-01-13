/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:20:30 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/13 14:45:20 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		check_input(t_fractol *fractol, char **argv)
{
	if (ft_strcmp("Julia", argv[1]) == 0)
	{
		fractol->argv = ft_strdup("Julia");
		fractol->title = ft_strdup("Julia");
		fractol->numbers = numbers_init(fractol);
		fractol->numbers->c_i = -0.7;
		fractol->numbers->c_real = 0.27015;
	}
	else if (ft_strcmp("Mandelbrot", argv[1]) == 0)
	{
		fractol->argv = ft_strdup("Mandelbrot");
		fractol->title = ft_strdup("Mandelbort");
		fractol->numbers = numbers_init(fractol);
	}
	else if (ft_strcmp("Jessie", argv[1]) == 0)
	{
		fractol->argv = ft_strdup("Jessie");
		fractol->title = ft_strdup("Jessie");
		fractol->numbers = numbers_init(fractol);
	}
	else
		fractol_exit(USAGE_ERR, fractol);
}

t_numbers	*numbers_init(t_fractol *fractol)
{
	t_numbers *number;

	number = (t_numbers*)ft_memalloc(sizeof(t_numbers));
	if (number == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	return (number);
}

t_fractol	*fractol_init(void)
{
	t_fractol *fractol;

	fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol));
	if (fractol == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	fractol->event.zoom = 1.0;
	return (fractol);
}

void		fractol_exit(char *str, t_fractol *fractol)
{
	ft_putstr(str);
	if (fractol != NULL)
	{
		ft_bzero(fractol, sizeof(t_fractol));
		free(fractol);
	}
	exit(0);
}
