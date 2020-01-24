/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_setup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:59:40 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/24 13:43:15 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mlx_setup(t_fractol *fractol)
{
	int endian;

	endian = 0;
	fractol->mlx_ptr = mlx_init();
	fractol->window_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH + 400, HEIGHT,\
		"THE AMAZING AND WONDERFUL FRACT'OL\n");
	if (fractol->window_ptr == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	fractol->image_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (fractol->image_ptr == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	fractol->addr_str = mlx_get_data_addr(fractol->image_ptr,\
					&fractol->bits_ppixel, &fractol->size_line, &endian);
	if (fractol->addr_str == NULL)
		fractol_exit(MALLOC_ERR, fractol);
}
