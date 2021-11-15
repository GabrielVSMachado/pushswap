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

int	check_chunck_sorted_in_b(t_list *lst, int lenght)
{
	while (--lenght)
	{
		if (*(int *)lst->content < *(int *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	less_than_mid_point(t_list *lst, int mid_point, int *less_than_index)
{
	*less_than_index = 0;
	while (lst)
	{
		if (*(int *)lst->content < mid_point)
			return (1);
		lst = lst->next;
		(*less_than_index)++;
	}
	return (0);
}

void	do_operation(int (*op)(), t_list **lst, const char *name_op)
{
	op(lst);
	ft_putendl_fd((char *)name_op, 1);
}

void	partition(t_list **from, t_list **to, int mid_point)
{
	int	n_index;

	n_index = 0;
	while (less_than_mid_point(*from, mid_point, &n_index))
	{
		if (*(int *)(*from)->content < mid_point)
		{
			push(from, to);
			ft_putendl_fd("pb", 1);
		}
		else if (*(int *)ft_lstlast(*from)->content < mid_point)
			do_operation(rotate_to_down, from, "rra");
		else
			do_operation(rotate_to_up, from, "ra");
	}
}
