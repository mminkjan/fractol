/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:14:59 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/23 19:31:21 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "../includes/thread.h"
# include <math.h>

# define USAGE_ERR "usage: input valid fractol\nJulia\nMandelbrot\nMandelbar\n"
# define MALLOC_ERR "error: malloc\n"

# define ONE 18
# define TWO 19
# define THREE 20

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

# define WIDTH 1000
# define HEIGHT 700

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
	double		key;
	int			freeze;
	double		color_set;
	int			mouse_press;
	double		mouse_x;
	double		mouse_y;
	double		hold_x;
	double		hold_y;
	int			color_grade;
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
	int			max_iterations;
	int			type;
	int			two;
	t_fractol	*next;
	t_color		color;
	t_events	event;
	t_numbers	*numbers;
	t_pixel		*pixel;
	t_render	render;
}				t_fractol;

int				main(int argc, char **argv);
void			mlx_setup(t_fractol *fractol);
int				fractol_manager(t_fractol *fractol);

void			check_input(t_fractol *fractol, char **argv);
void			fractol_exit(char *str, t_fractol *fractol);
t_fractol		*fractol_init(void);

void			check_input(t_fractol *fractol, char **argv);

int				key_press(int key, t_fractol *fractol);

int				mouse_press(int key, int x, int y, t_fractol *fractol);
int				mouse_release(int key, int x, int y, t_fractol *fracol);
int				mouse_move(int x, int y, t_fractol *fractol);

void			print_interface(t_fractol *fractol);
#endif
