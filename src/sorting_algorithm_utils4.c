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

void	exec_action(struct s_less_movs *action, t_stacks **stacks)
{
	while ((action->which_mov_a == 1 && action->which_mov_b == 1)
		&& (action->act_stack_a && action->act_stack_b))
	{
		do_operation(rotate_to_down, &(*stacks)->stack_a, "rrr");
		do_operation(rotate_to_down, &(*stacks)->stack_b, NULL);
		action->act_stack_a--;
		action->act_stack_b--;
	}
	while ((action->which_mov_a == 0 && action->which_mov_b == 0)
		&& (action->act_stack_a && action->act_stack_b))
	{
		do_operation(rotate_to_up, &(*stacks)->stack_a, "rr");
		do_operation(rotate_to_up, &(*stacks)->stack_b, NULL);
		action->act_stack_a--;
		action->act_stack_b--;
	}
	while (action->which_mov_a && action->act_stack_a-- > 0)
		do_operation(rotate_to_down, &(*stacks)->stack_a, "rra");
	while (!action->which_mov_a && action->act_stack_a-- > 0)
		do_operation(rotate_to_up, &(*stacks)->stack_a, "ra");
	while (action->which_mov_b && action->act_stack_b-- > 0)
		do_operation(rotate_to_down, &(*stacks)->stack_b, "rrb");
	while (!action->which_mov_b && action->act_stack_b-- > 0)
		do_operation(rotate_to_up, &(*stacks)->stack_b, "rb");
}

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
