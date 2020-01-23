/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:20:30 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/23 20:08:52 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol			*fractol_init(void)
{
	t_fractol *fractol;

	fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol));
	if (fractol == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	fractol->pixel = (t_pixel*)ft_memalloc(sizeof(t_pixel) * WIDTH * HEIGHT);
	if (fractol->pixel == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	fractol->event.zoom = 1.0;
	fractol->max_iterations = 190;
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
	if (fractol != NULL && fractol->pixel != NULL)
	{
		ft_bzero(fractol->pixel, sizeof(t_pixel));
		free(fractol->numbers);
	}
	if (fractol != NULL)
	{
		while (fractol->next != NULL)
		{
			ft_bzero(fractol, sizeof(t_fractol));
			free(fractol);
		}
		ft_bzero(fractol, sizeof(t_fractol));
		free(fractol);
	}
	exit(0);
}
