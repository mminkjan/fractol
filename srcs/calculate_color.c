/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_color.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 18:35:13 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/14 16:20:15 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		RGB_to_HEX(t_fractol *fractol, double r, double g, double b)
{
	fractol->color = (((int)r & 0xff) << 16) + (((int)g & 0xff) << 8) + ((int)b & 0xff);
}

static void		HSV_to_RGB(t_fractol *fractol)
{
	int	hue_integer;
	double f;
	double p;
	double q;
	double t;
	
	if (fractol->saturation == 0.0)
		RGB_to_HEX(fractol, fractol->value, fractol->value, fractol->value);
	else
	{
		hue_integer = (int)fractol->hue * 6.0;
		f = (fractol->hue * 6.0) - hue_integer;
		p = fractol->value * (1.0 - fractol->saturation);
		q = fractol->value * (1.0 - fractol->saturation * f);
		t = fractol->value * (1.0 - fractol->saturation * (1.0 - f));
		hue_integer %= 6;
		if (hue_integer == 0)
			RGB_to_HEX(fractol, fractol->value, t, q);
		else if (hue_integer == 1)
			RGB_to_HEX(fractol, q, fractol->value, p);
		else if (hue_integer == 2)
			RGB_to_HEX(fractol, p, fractol->value, t);
		else if (hue_integer == 3)
			RGB_to_HEX(fractol, p, q, fractol->value);
		else if (hue_integer == 4)
			RGB_to_HEX(fractol, t, p, fractol->value);
		else if (hue_integer == 5)
			RGB_to_HEX(fractol, fractol->value, p, q);
	}
}


void			calculate_color(t_fractol *fractol, double smooth)
{
	fractol->hue = (int)(255 * smooth / MAX_ITERATIONS);
	printf("hue: %f\n", fractol->hue);
	if (fractol->hue < 0)
		printf("smooth  = %f\n", smooth);
	fractol->saturation = 255;
	fractol->value = 255;
	if (smooth < MAX_ITERATIONS)
		fractol->value = 0;
	HSV_to_RGB(fractol);
}