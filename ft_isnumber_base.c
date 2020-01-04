/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnumber_base.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jessicasmith <jessicasmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/13 21:02:41 by jessicasmit    #+#    #+#                */
/*   Updated: 2020/01/04 13:35:15 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

int		ft_isnumber_base(char *nb, int base)
{
	int	neg;
	int	new;

	neg = 1;
	new = 0;
	if (*nb == '-')
	{
		neg = -1;
		nb++;
	}
	if (*nb == '+')
		nb++;
	while (*nb != 0 && *nb >= '0' && *nb <= '9')
	{
		new = new * base + (*nb - '0');
		nb++;
	}
	return ((ft_isdigit(new * neg) ? true : false));
}
