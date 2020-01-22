/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_fractol.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 12:23:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/22 15:46:47 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	put_pixel(t_fractol *fractol, int color, int x, int y)
{
	size_t	index;

	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		index = (y * fractol->size_line) + (x * fractol->bits_ppixel / 8);
		fractol->addr_str[index] = color;
		index++;
		fractol->addr_str[index] = color >> 8;
		index++;
		fractol->addr_str[index] = color >> 16;
	}
}

void		draw_fractol(t_fractol *fractol)
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
				color = get_color(fractol, (float)pixel.i);
			else
				color = 0x000000;
			put_pixel(fractol, color, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, \
		fractol->window_ptr, fractol->image_ptr, 400, 0);
}
