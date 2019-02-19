/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddback.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 21:19:20 by jesmith        #+#    #+#                */
/*   Updated: 2019/02/10 17:12:21 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list *alst, t_list *blst)
{
	if (alst == NULL)
	{
		alst = blst;
		return ;
	}
	while (alst->next != NULL)
		alst = alst->next;
	alst->next = blst;
	return ;
}
