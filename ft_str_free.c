/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/17 10:16:35 by jesmith        #+#    #+#                */
/*   Updated: 2019/10/17 10:17:10 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_free_str(char **values_str)
{
	size_t index;

	index = 0;
	while (values_str[index])
	{
		free(values_str[index]);
		index++;
	}
	free(values_str[index]);
}
