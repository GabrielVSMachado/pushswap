/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:27:05 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/10/21 16:27:05 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return (1);
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	return (0);
}

int	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!from || !to || !*from)
		return (1);
	tmp = *to;
	(*to) = (*from);
	(*from) = (*from)->next;
	(*to)->next = tmp;
	return (0);
}

int	rotate_to_up(t_list **stack)
{
	t_list	*last_node;
	int		size;	

	if (!stack || !*stack)
		return (1);
	size = ft_lstsize(*stack);
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	(*stack) = (*stack)->next;
	last_node = (*stack);
	while (--size)
		last_node = last_node->next;
	last_node->next = NULL;
	return (0);
}

int	rotate_to_down(t_list **stack)
{
	t_list	*last_node;
	int		size_lst;

	if (!stack || !*stack)
		return (1);
	size_lst = ft_lstsize(*stack);
	last_node = ft_lstlast(*stack);
	last_node->next = (*stack);
	(*stack) = last_node;
	last_node = (*stack);
	while (--size_lst)
		last_node = last_node->next;
	last_node->next = NULL;
	return (0);
}
