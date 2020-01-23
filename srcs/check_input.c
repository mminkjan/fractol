/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:15:10 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/23 20:06:56 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

static t_numbers	*numbers_init(t_fractol *fractol)
{
	t_numbers *number;

	number = (t_numbers*)ft_memalloc(sizeof(t_numbers));
	if (number == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	return (number);
}

static void			fractol_info(t_fractol *fractol, char *argv)
{
	if (ft_strcmp("Julia", argv) == 0)
	{
		fractol->argv = ft_strdup("Julia");
		fractol->numbers = numbers_init(fractol);
		fractol->type = 1;
		fractol->numbers->c_real = -0.7;
		fractol->numbers->c_i = 0.27015;
		fractol->two = 2;
	}
	else if (ft_strcmp("Mandelbrot", argv) == 0)
	{
		fractol->argv = ft_strdup("Mandelbrot");
		fractol->numbers = numbers_init(fractol);
		fractol->type = 2;
		fractol->two = 2;
	}
	else if (ft_strcmp("Mandelbar", argv) == 0)
	{
		fractol->argv = ft_strdup("Mandelbar");
		fractol->numbers = numbers_init(fractol);
		fractol->type = 3;
		fractol->two = -2;
	}
	else
		fractol_exit(USAGE_ERR, fractol);
}

void				check_input(t_fractol *fractol, char **argv)
{
	size_t		index;
	t_fractol	*head;

	index = 1;
	head = fractol;
	while (argv[index])
	{
		if (index > 1)
		{
			fractol->next = fractol_init();
			fractol = fractol->next;
			fractol->next = NULL;
		}
		fractol_info(fractol, argv[index]);
		index++;
	}
	fractol = head;
}
