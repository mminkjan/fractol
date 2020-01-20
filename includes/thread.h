/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 10:25:31 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 13:39:41 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _THREAD_
# define _THREAD_

# include <pthread.h>
# include "../includes/fractol.h"

# define THREADS 8

# define LINEAR 256

typedef struct  s_fractol	t_fractol;

typedef struct	s_thread
{
	int			id;
	t_fractol	*fractol;
}				t_thread;

typedef struct	s_render
{
	pthread_t	thread[THREADS];
	t_thread	args[THREADS];
}				t_render;

int			fractol_writer(t_fractol *fractol);
int			get_color(t_fractol *fractol, double iterations);
void		draw_fractol(t_fractol *fractol);
t_render	*render_init(t_fractol *fractol);

#endif