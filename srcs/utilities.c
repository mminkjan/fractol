/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:20:30 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/08 16:58:29 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol	*fractol_init(void)
{
	t_fractol *fractol;

	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (fractol == NULL)
		fractol_exit(MALLOC_ERR);
	ft_bzero(fractol, sizeof(t_fractol));
	return (fractol);
}

void	fractol_exit(char *str)
{
	ft_putstr(str);
	exit(0);
}
