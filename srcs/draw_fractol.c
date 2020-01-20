/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fractol.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 12:23:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 13:46:39 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_fractol *fractol, size_t index, int x, int y)
{
	int		color;
	size_t	sub_dex;

	color = fractol->color.color_ppixel[index];
	sub_dex = (y * fractol->size_line + x * fractol->bits_ppixel / 8);
	fractol->addr_str[sub_dex] = color;
	sub_dex++;
	fractol->addr_str[sub_dex] = color >> 8;
	sub_dex++;
	fractol->addr_str[sub_dex] = color >> 16;
}

void	draw_fractol(t_fractol *fractol)
{
	int		x;
	int		y;
	size_t	index;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			index = y * WIDTH + x;
			if (fractol->i != fractol->max_iterations)
				put_pixel(fractol, index, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr, fractol->image_ptr, 400, 0);
}
