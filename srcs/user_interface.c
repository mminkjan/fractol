/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_interface.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 20:41:34 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/18 20:47:28 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		print_side_line(t_fractol *fractol)
{
	int y;
	int color;

	y = 0;
	color = 0xfafafaf;
	while (y < HEIGHT)
	{
		mlx_pixel_put(fractol->mlx_ptr, fractol->window_ptr, 399, y, color);
		y++;
	}
}

void			print_interface(t_fractol *fractol)
{
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 210, 0xafafaf,
		"zoom:             		scroll\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 240, 0xafafaf,
		"change max iteration:   + & -\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 270, 0xafafaf,
		"change color:     		spacebar\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 300, 0xafafaf,
		"change fractol:   		1, 2, & 3\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 360, 0xafafaf,
		"press and drag mouse to move fractal\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 410, 0xafafaf,
		"reset:            		backspace\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 440, 0xafafaf,
		"quit:            		escape\n");
	print_side_line(fractol);
}
