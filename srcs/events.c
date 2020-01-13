/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:22:02 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/13 14:29:34 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_press(int key, t_fractol *fractol)
{
	if (key == ESC)
	{
		ft_bzero(fractol, sizeof(fractol));
		free(fractol);
		exit(0);
	}
	return (0);
}

// int		mouse_scroll(int key)
// {

// }

// int		mouse_press(int key)
// {

// }

// int		mouse_release(int key)
// {

// }
