/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_utils4.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:33:30 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/24 17:33:30 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_lower(int element, int index, int *ord_array)
{
	return (index - 1 >= 0 && element == ord_array[index - 1]);
}

int	cmp_higher(int element, int index, int *ord_array)
{
	return (element == ord_array[index]);
}

t_list	*find_element(t_list *stack, int element,
		int *ord_array, int (*cmp)(int, int, int*))
{
	int	index;

	index = 0;
	while (ord_array[index] < element)
		index++;
	while (stack)
	{
		if (cmp(*(int *)stack->content, index, ord_array))
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
