/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fractol.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 12:23:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 21:03:09 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_fractol *fractol, int color, int x, int y)
{
	size_t	sub_dex;

	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		sub_dex = (y * fractol->size_line) + (x * fractol->bits_ppixel / 8);
		fractol->addr_str[sub_dex] = color;
		sub_dex++;
		fractol->addr_str[sub_dex] = color >> 8;
		sub_dex++;
		fractol->addr_str[sub_dex] = color >> 16;
	}
}

void	draw_fractol(t_fractol *fractol)
{
	int		x;
	int		y;
	int		color;
	size_t	index;
	t_pixel	pixel;
	

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			index = y * WIDTH + x;
			pixel = fractol->pixel[index];
			if (pixel.i < fractol->max_iterations)
				color = get_color(fractol, pixel.i);
				// color = 0xffffff;
				// fractol->color.color_ppixel[index] = 0xfffff;
			// }
			else
				color = 0x000000;
			// 	fractol->color.color_ppixel[index] = 0x000000;
			// fractol->color.color_ppixel[index] =  get_color(fractol, fractol->i);
			// printf("%x\n", color);
			put_pixel(fractol, color, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr, fractol->image_ptr, 400, 0);
}
