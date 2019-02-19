/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 15:20:28 by jesmith       #+#    #+#                 */
/*   Updated: 2019/02/08 19:09:06 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int c;
	int r;

	c = 1;
	r = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		c = -1;
		str++;
		if (*str == '+')
			return (0);
	}
	if (*str == '+')
		str++;
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (r * c);
}
