/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 21:39:07 by jesmith       #+#    #+#                 */
/*   Updated: 2019/02/08 18:58:26 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *data, size_t size)
{
	if (data == NULL)
		return ;
	ft_bzero(data, size);
	free(data);
	data = NULL;
	size = 0;
}
