/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:23:42 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/10/08 16:23:42 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **lst)
{
	t_list	*temp;

	if (!(*lst)->next)
		return (1);
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	return (0);
}

int	push(t_list **from, t_list **to)
{
	(*to) = (*from);
	(*from) = (*from)->next;
	(*to)->next = NULL;
	return (0);
}
