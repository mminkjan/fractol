/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 15:20:28 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/04 13:23:11 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, int base)
{
	int neg;
	int result;

	neg = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
		if (*str == '+')
			return (0);
	}
	if (*str == '+')
		str++;
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		result = result * base + (*str - '0');
		str++;
	}
	return (result * neg);
}
