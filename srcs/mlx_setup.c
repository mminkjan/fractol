/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_setup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:59:40 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/18 16:11:34 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mlx_setup(t_fractol *fractol)
{
	int endian;

	endian = 0;
	fractol->mlx_ptr = mlx_init();
	fractol->window_ptr = mlx_new_window(fractol->mlx_ptr,\
							WIDTH + 400, HEIGHT, fractol->argv);
	fractol->image_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->addr_str = mlx_get_data_addr(fractol->image_ptr,\
					&fractol->bits_ppixel, &fractol->size_line, &endian);
}
