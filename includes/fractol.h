/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:14:59 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/08 17:18:06 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define USAGE_ERR "usage error: \
					input valid parameter\nJulia\nMandelbrot\nJessie"
# define MALLOC_ERR "error: malloc\n"

# define ONE 49
# define TWO 50
# define THREE 51
# define ESC 27

# define MAX_ITERATIONS 256

# define WIDTH 1900
# define HEIGHT 1200

# include <stdio.h> //remove later!

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*window_ptr;
	void		*image_ptr;
	char		*title;
	char		*addr_str;
	int			bits_ppixel;
	int			size_line;
}				t_fractol;

int			main(int argc, char **argv);
void		mlx_setup(t_fractol *fractol);
int			fractol_manager(t_fractol *fractol);

void		fractol_exit(char *str);
t_fractol	*fractol_init(void);

#endif
