/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:09:45 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/11 14:30:44 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_input(t_fractol *fractol, char **argv)
{
	if (ft_strcmp("Julia", argv[1]) == 0)
	{
		fractol->argv = ft_strdup("Julia");
		fractol->numbers->c_i = -0.7;
		fractol->numbers->c_real = 0.27015;
	}
	else if (ft_strcmp("Mandelbrot", argv[1]) == 0)
		fractol->argv = ft_strdup("Mandelbrot");
	else if (ft_strcmp("Jessie", argv[1]) == 0)
		fractol->argv = ft_strdup("Jessie");
	else
		fractol_exit(USAGE_ERR, fractol);
}

int		main(int argc, char **argv)
{
	t_fractol *fractol;

	fractol = NULL;
	if (argc != 2)
		fractol_exit(USAGE_ERR, fractol);
	fractol = fractol_init();
	check_input(fractol, argv);
	fractol->title = ft_strdup(argv[1]);
	mlx_setup(fractol);
	mlx_key_hook(fractol->window_ptr, fractol_manager, fractol);
	mlx_loop(fractol->mlx_ptr);
}
