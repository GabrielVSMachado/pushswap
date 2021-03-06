/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:11:55 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/08 17:11:55 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_lenght(int mid_point, int *array)
{
	int	lenght;

	lenght = 0;
	while (array[lenght] != mid_point)
		lenght++;
	return (lenght);
}

int	less_than_mid_point(t_list *lst, int mid_point, int lower)
{
	while (lst)
	{
		if (*(int *)lst->content < mid_point
			&& *(int *)lst->content != lower)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	do_operation(int (*op)(), t_list **lst, const char *name_op)
{
	op(lst);
	if (name_op != NULL)
		ft_putendl_fd((char *)name_op, 1);
}

void	partition(t_list **from, t_list **to, int mid_point, int lower)
{
	while (less_than_mid_point(*from, mid_point, lower))
	{
		if (*(int *)(*from)->content < mid_point
				&& *(int *)(*from)->content != lower)
		{
			push(from, to);
			ft_putendl_fd("pb", 1);
		}
		else if (*(int *)ft_lstlast(*from)->content < mid_point
			&& *(int *)ft_lstlast(*from)->content != lower)
			do_operation(rotate_to_down, from, "rra");
		else
			do_operation(rotate_to_up, from, "ra");
	}
}
