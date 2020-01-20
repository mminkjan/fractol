/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_render.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:35:20 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 13:39:51 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_render	*render_init(t_fractol *fractol)
{
	t_render *temp;

	temp = (t_render*)ft_memalloc(sizeof(t_render));
	if (temp == NULL)
		fractol_exit(MALLOC_ERR, fractol);
	return (temp);
}