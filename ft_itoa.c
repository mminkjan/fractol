/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 09:53:18 by jesmith        #+#    #+#                */
/*   Updated: 2019/02/10 17:47:12 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		neg;
	size_t	i;

	i = 0;
	neg = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = (char *)malloc(ft_intlen(n) + 1);
	if (!res)
		return (NULL);
	if (n < 0)
		n = -n;
	if (n == 0)
		res[i] = '0';
	while (n > 0)
	{
		res[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (neg < 0)
		res[i] = '-';
	res[ft_intlen(neg)] = '\0';
	return (ft_strrev(res));
}
