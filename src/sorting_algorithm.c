/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:48:43 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/02 13:48:43 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_chunck_sorted(t_list *lst, int lenght)
{
	while (--lenght)
	{
		if (*(int *)lst->content < *(int *)lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	less_than_mid_point(t_list *lst, int mid_point, int *less_than_index)
{
	*less_than_index = 0;
	while (lst->next)
	{
		if (*(int *)lst->content < mid_point)
			return (1);
		lst = lst->next;
		(*less_than_index)++;
	}
	return (0);
}

void	do_operation(int (*op)(), t_list **lst, char *name_op)
{
	op(lst);
	write(1, name_op, ft_strlen(name_op));
	write(1, "\n", 1);
}

void	partition(t_list **stack_from, t_list **stack_to, char **names_op,
			int mid_point)
{
	int	n_index;
	int	m_index;

	n_index = 0;
	m_index = ft_lstsize(*stack_from) / 2;
	while (less_than_mid_point(*stack_from, mid_point, &n_index))
	{
		if (*(int *)(*stack_from)->content < mid_point)
		{
			push(stack_from, stack_to);
			write(1, *names_op, 2);
			write(1, "\n", 1);
		}
		else if (n_index < m_index)
			do_operation(rotate_to_up, stack_from, *(names_op + 1));
		else
			do_operation(rotate_to_down, stack_from, *(names_op + 2));
	}
}
