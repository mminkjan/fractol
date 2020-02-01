/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 11:02:19 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/01 14:03:52 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "thread.h"
# include <math.h>

# define FRACTOLS "Julia\nMandelbrot\nMandelbar\nBurningShip\n"
# define USAGE_ERR "usage: input valid fractol\n" FRACTOLS
# define MALLOC_ERR "error: malloc\n"

# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21

# define ONE_START 0x0B171A
# define ONE_MIDDLE 0xE6DADA
# define ONE_END 0xFFFFFF

# define TWO_START 0x000000
# define TWO_MIDDLE 0xB21F1F
# define TWO_END 0xFDBB2D

# define THREE_START 0xFFF8DE
# define THREE_MIDDLE 0xF7971E
# define THREE_END 0x956900

# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MOUSE_PRESS 1

# define ESC 53
# define INCREASE_ITERATIONS 24
# define DECREASE_ITERATIONS 27
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define FREEZE 261
# define SPACE 49
# define RESET 51

# define WIDTH 600
# define HEIGHT 600

typedef struct s_fractol	t_fractol;

typedef t_pixel	(*t_f_ptr)(t_fractol *fractol, int x, int y);

typedef struct	s_numbers
{
	double		c_real;
	double		c_i;
	double		new_real;
	double		new_i;
	double		old_real;
	double		old_i;
}				t_numbers;

typedef struct	s_events
{
	double		zoom;
	int			freeze;
	int			color_set;
	int			color_grade;
	int			mouse_press;
	double		mouse_x;
	double		mouse_y;
	double		hold_x;
	double		hold_y;
}				t_events;

typedef struct	s_color
{
	int			start;
	int			end;
	double		hue;
	double		saturation;
	double		value;
	int			color_ppixel[HEIGHT * WIDTH];
}				t_color;

struct			s_fractol
{
	void		*mlx_ptr;
	void		*window_ptr;
	void		*image_ptr;
	char		*addr_str;
	int			bits_ppixel;
	int			size_line;
	char		*argv;
	int			max_iterations;
	int			type;
	t_f_ptr		selector;
	double		c_real;
	double		c_i;
	t_color		color;
	t_events	event;
	t_pixel		*pixel;
	t_render	render;
};

int				main(int argc, char **argv);
void			mlx_setup(t_fractol *fractol);
int				fractol_manager(t_fractol *fractol);

void			check_input(t_fractol *fractol, char *argv);
void			fractol_exit(char *str, t_fractol *fractol);
t_fractol		*fractol_init(void);

t_pixel			julia_fractol(t_fractol *fractol, int x, int y);
t_pixel			mandelbrot_fractol(t_fractol *fractol, int x, int y);
t_pixel			mandelbar_fractol(t_fractol *fractol, int x, int y);
t_pixel			burningship_fractol(t_fractol *fractol, int x, int y);

int				key_press(int key, t_fractol *fractol);
void			fractol_key(int key, t_fractol *fractol);
void			reset_key(t_fractol *fractol);

int				mouse_press(int key, int x, int y, t_fractol *fractol);
int				mouse_release(int key, int x, int y, t_fractol *fracol);
int				mouse_move(int x, int y, t_fractol *fractol);
int				close_window(t_fractol *fractol);

void			print_interface(t_fractol *fractol);
#endif
