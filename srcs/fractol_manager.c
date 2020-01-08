/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_manager.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:11:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/08 17:17:48 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		fractol_manager(t_fractol *fractol)
{
	mlx_key_hook(fractol->window_ptr, key_press, fractol);
	mlx_key_hook(fractol->window_ptr, mouse_scroll, fractol);
	mlx_key_hook(fractol->window_ptr, mouse_press, fractol);
	mlx_key_hook(fractol->window_ptr, mouse_release, fractol);
	//fractol_draw
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr,\
		fractol->image_ptr, 0, 0);
	ft_bzero(fractol->addr_str, (fractol->bits_ppixel / 8) *WIDTH * HEIGHT);
	return (0);
}
