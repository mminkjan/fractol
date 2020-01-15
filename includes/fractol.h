/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:14:59 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/15 12:11:05 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define USAGE_ERR "usage error: input valid parameter\
						\nJulia\nMandelbrot\nJessie\n"
# define MALLOC_ERR "error: malloc\n"

# define ONE 18
# define TWO 19
# define THREE 20


# define ONE_START 0xffffff
# define TWO_START 0xFF238A
# define THREE_START 0x23FFF8

# define ONE_MIDDLE 0xC70039
# define TWO_MIDDLE 0x29A965
# define THREE_MIDDLE 0x2972A9

# define ONE_END 0x581845
# define TWO_END 0x46037D
# define THREE_END 0xFF0000

# define DEFAULT_START 0xffa500
# define DEFAULT_MIDDLE 0xee3a6a
# define DEFAULT_END 0x72b2f3

# define ESC 53
# define MOVE_UP 126
# define MOVE_DOWN 125
# define MOVE_LEFT 123
# define MOVE_RIGHT 124
# define INCREASE_ITERATIONS 24
# define DECREASE_ITERATIONS 27
# define INCREASE_IMAGINARY 12
# define DECREASE_IMAGINARY 13
# define INCREASE_REAL 14
# define DECREASE_REAL 15

# define MAX_ITERATIONS 150


# define WIDTH 1200
# define HEIGHT 1000

# include <math.h>
# include <stdio.h> //remove later!

typedef struct	s_numbers
{
	double		c_real; //for Julia
	double		c_i;
	double		new_real;
	double		new_i;
	double		old_real;
	double		old_i;
	double		pixel_real; // for Mandelbort
	double		pixel_i;
}				t_numbers;

typedef struct	s_events
{
	double		zoom;
	double		key;
	int			color_start;
	int			color_middle;
	int			color_end;
	double		mouse_x;
	double		mouse_y;
}				t_events;

typedef struct	s_points
{
	double		x;
	double		y;
}				t_points;

typedef struct s_color
{
	int			start;
	int			end;
	int			color_3;
}				t_color;

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*window_ptr;
	void		*image_ptr;
	char		*title;
	char		*addr_str;
	int			bits_ppixel;
	int			size_line;
	char		*argv;
	int			type;
	int			rgb_color;
	double		hue;
	double		saturation;
	double		value;
	t_color		color;
	t_events	event;
	t_numbers	*numbers;
	t_points	*points;
}				t_fractol;

int				main(int argc, char **argv);
void			mlx_setup(t_fractol *fractol);
int				fractol_manager(t_fractol *fractol);

void			check_input(t_fractol *fractol, char **argv);
void			fractol_exit(char *str, t_fractol *fractol);
t_fractol		*fractol_init(void);
t_numbers		*numbers_init(t_fractol *fractol);
t_points		*points_init(t_fractol *fractol);

int				get_color(t_fractol *fractol, int iteration);
// void			calculate_color(t_fractol *fractol, double smooth, size_t iteration);

int				key_press(int key, t_fractol *fractol);
#endif
