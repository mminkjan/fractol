/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarradel.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 18:35:18 by jesmith       #+#    #+#                 */
/*   Updated: 2019/02/08 19:25:18 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarradel(const char *s)
{
	if (*s == '\0')
		ft_memdel((void **)(s));
	return ;
}
