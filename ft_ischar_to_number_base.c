/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnumber_base.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jessicasmith <jessicasmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/13 21:02:41 by jessicasmit    #+#    #+#                */
/*   Updated: 2019/10/13 21:13:13 by jessicasmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

int		ft_ischar_to_number_base(char *str, int base)
{
	int		neg;
	int 	ret_val;
	int		nb;

	neg = 1;
	nb = 0;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	if (*str == '+')
		str++;
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		nb = nb * base + (*str + '0');
		str++;
	}
	return (!(ft_isdigit(nb * neg) ? true : false));
}
