/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:20:30 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 13:44:57 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		check_input(t_fractol *fractol, char **argv)
{
	if (ft_strcmp("Julia", argv[1]) == 0)
	{
		fractol->argv = ft_strdup("Julia");
		fractol->type = 1;
		fractol->numbers = numbers_init(fractol);
		fractol->numbers->c_real = -0.7;
		fractol->numbers->c_i = 0.27015;
	}
	else if (ft_strcmp("Mandelbrot", argv[1]) == 0)
	{
		fractol->argv = ft_strdup("Mandelbrot");
		fractol->type = 2;
		fractol->numbers = numbers_init(fractol);
	}
	else if (ft_strcmp("Jessie", argv[1]) == 0)
	{
		fractol->argv = ft_strdup("Jessie");
		fractol->type = 3;
		fractol->numbers = numbers_init(fractol);
		fractol->numbers->c_real = 0.3;
		fractol->numbers->c_i = -0.01;
	}
	else
		fractol_exit(USAGE_ERR, fractol);
	fractol->render = render_init(fractol);
}

t_numbers	*numbers_init(t_fractol *fractol)
{
	t_numbers *number;

	number = (t_numbers*)ft_memalloc(sizeof(t_numbers));
	if (number == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	return (number);
}

t_points	*points_init(t_fractol *fractol)
{
	t_points *points;

	points = (t_points*)ft_memalloc(sizeof(t_points));
	if (points == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	return (points);
}

t_fractol	*fractol_init(void)
{
	t_fractol *fractol;

	fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol));
	if (fractol == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	fractol->event.zoom = 1.0;
	fractol->max_iterations = 150;
	fractol->color.saturation = 100;
	fractol->color.value = 50;
	fractol->color.start = DEFAULT_START;
	fractol->color.end = DEFAULT_END;
	return (fractol);
}

void		fractol_exit(char *str, t_fractol *fractol)
{
	ft_putstr(str);
	if (fractol != NULL && fractol->points != NULL)
	{
		ft_bzero(fractol->points, sizeof(t_points));
		free(fractol->points);
	}
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
