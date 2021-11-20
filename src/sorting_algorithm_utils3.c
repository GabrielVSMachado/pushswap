/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_utils3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:42:27 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/20 15:42:27 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_of_rra(t_list *stack, const t_list *element)
{
	int		result;
	int		size;

	result = 0;
	size = ft_lstsize(stack);
	while (stack)
	{
		if (*(int *)stack->content == *(int *)element->content)
			break ;
		result++;
		stack = stack->next;
	}
	return (ft_abs(result - size));
}
