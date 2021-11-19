/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms_utils3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:04:59 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/18 18:04:59 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_of_op(t_list *stack, const t_list *element, int (*op)())
{
	int	result;

	result = 0;
	while (stack && stack != element)
	{
		op(&stack);
		result++;
		stack = stack->next;
	}
	return (result);
}
