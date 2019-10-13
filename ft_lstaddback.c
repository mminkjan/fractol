/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddback.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 21:19:20 by jesmith        #+#    #+#                */
/*   Updated: 2019/10/13 21:04:05 by jessicasmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddback(t_list **alst, t_list *blst)
{
	t_list *temp;

	temp = *alst;
	if (temp == NULL)
	{
		*alst = blst;
		return (blst);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = blst;
	return (blst);
}
