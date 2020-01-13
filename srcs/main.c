/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:09:45 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/13 18:17:32 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			main(int argc, char **argv)
{
	t_fractol *fractol;

	fractol = NULL;
	if (argc != 2)
		fractol_exit(USAGE_ERR, fractol);
	fractol = fractol_init();
	check_input(fractol, argv);
	fractol->points = points_init(fractol);
	mlx_setup(fractol);
	mlx_loop_hook(fractol->mlx_ptr, fractol_manager, fractol);
	mlx_loop(fractol->mlx_ptr);
	return (0);
}
