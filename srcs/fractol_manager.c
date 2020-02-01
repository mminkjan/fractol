/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_manager.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:11:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/01 13:49:11 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			put_pixel(t_fractol *fractol, int x, int y, int color)
{
	size_t		index;

	if (x >= 0 && x < WIDTH && \
			y >= 0 && y < HEIGHT)
	{
		index = (y * fractol->size_line) + (x * fractol->bits_ppixel / 8);
		fractol->addr_str[index] = color;
		index++;
		fractol->addr_str[index] = color >> 8;
		index++;
		fractol->addr_str[index] = color >> 16;
	}
}

static void		draw_fractol(t_fractol *fractol)
{
	t_events	events;
	int			x;
	int			y;

	y = 0;
	events = fractol->event;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractol->selector(fractol, x, y);
			x++;
		}
		y++;
	}
	y = 0;
}

static void		hook_events(t_fractol *fractol)
{
	mlx_key_hook(fractol->window_ptr, key_press, fractol);
	mlx_hook(fractol->window_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->window_ptr, 6, 0, mouse_move, fractol);
	mlx_hook(fractol->window_ptr, 5, 0, mouse_release, fractol);
	mlx_hook(fractol->window_ptr, 17, 0, close_window, fractol);
}

int				fractol_manager(t_fractol *fractol)
{
	hook_events(fractol);
	draw_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr,\
		fractol->image_ptr, 400, 0);
	ft_bzero(fractol->addr_str, (fractol->bits_ppixel / 8) * WIDTH * HEIGHT);
	return (0);
}
