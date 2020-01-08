/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:09:45 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/08 17:19:02 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_fractol *fractol;

	if (argc != 2)
		fractol_exit(USAGE_ERR);
	check_input(argv);
	fractol = fractol_init();
	fractol->title = ft_strdup(argv[1]);
	mlx_setup(fractol);
	mlx_key_hook(fractol->window_ptr, fractol_manager, fractol);
	mlx_loop(fractol->mlx_ptr);
}
