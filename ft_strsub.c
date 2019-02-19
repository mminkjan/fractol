/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:09:03 by jesmith        #+#    #+#                */
/*   Updated: 2019/02/10 19:17:03 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	new = ft_memalloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < start && s[i] != '\0')
		i++;
	if (i == start)
	{
		while (j < len)
		{
			new[j] = s[i];
			j++;
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
