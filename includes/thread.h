/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 10:25:31 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/27 13:46:02 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <pthread.h>
# include "../includes/fractol.h"

# define THREADS 8

typedef struct s_fractol	t_fractol;

typedef struct	s_thread
{
	int			id;
	t_fractol	*fractol;
}				t_thread;

typedef struct	s_render
{
	pthread_t	threads[THREADS];
	t_thread	args[THREADS];
}				t_render;

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct	s_pixel
{
	t_complex	complex;
	int			iterations;
}				t_pixel;

int				fractol_writer(t_fractol *fractol);
void			draw_fractol(t_fractol *fractol);

int				get_color(t_fractol *fractol, double iterations);
int				hsv_color(double iterations);

#endif
