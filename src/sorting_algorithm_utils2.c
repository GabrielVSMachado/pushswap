/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_utils2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:26:20 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/14 09:26:20 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	*make_int_array(t_list *lst)
{
	int		*array;
	int		counter;
	int		size;

	size = ft_lstsize(lst);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	counter = 0;
	while (counter < size)
	{
		array[counter] = *(int *)lst->content;
		lst = lst->next;
		counter++;
	}
	quick_sort(array, 0, size - 1);
	return (array);
}

/* calculate the number of rr(a or b)'s instruction
 * to put on top or on bottom of
 * stack the element */
int	number_of_rr(t_list *stack, const t_list *element)
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

/* calculate the number of r(a or b)'s instruction
 * to put the higher on top or the lower on bottom of
 * stack the element */
int	number_of_r(t_list *stack, const t_list *element)
{
	int		result;

	result = 0;
	while (*(int *)stack->content != *(int *)element->content)
	{
		result++;
		stack = stack->next;
	}
	return (result);
}

int	make_decision(t_stacks **stacks)
{
	struct s_less_movs	*action;

	action = calculate_moviments(stacks);
	if (!action)
		return (ERROR);
	if (action->which_mov_a != action->which_mov_b)
	{
		while (action->which_mov_a && action->act_stack_a-- > 0)
			do_operation(rotate_to_down, &(*stacks)->stack_a, "rra");
		while (!action->which_mov_a && action->act_stack_a-- > 0)
			do_operation(rotate_to_up, &(*stacks)->stack_a, "ra");
		while (action->which_mov_b && action->act_stack_b-- > 0)
			do_operation(rotate_to_down, &(*stacks)->stack_b, "rrb");
		while (!action->which_mov_b && action->act_stack_b-- > 0)
			do_operation(rotate_to_up, &(*stacks)->stack_b, "rb");
		push(&(*stacks)->stack_b, &(*stacks)->stack_a);
		ft_putendl_fd("pa", 1);
	}
	else
	{
		if (action->which_mov_a && action->which_mov_b)
		{
			while (action->act_stack_a && action->act_stack_b)
			{
				do_operation(rotate_to_down, &(*stacks)->stack_a, "rrr");
				do_operation(rotate_to_down, &(*stacks)->stack_b, NULL);
				action->act_stack_a--;
				action->act_stack_b--;
			}
			while (action->act_stack_a-- > 0)
				do_operation(rotate_to_down, &(*stacks)->stack_a, "rra");
			while (action->act_stack_b-- > 0)
				do_operation(rotate_to_down, &(*stacks)->stack_b, "rrb");
			push(&(*stacks)->stack_b, &(*stacks)->stack_a);
			ft_putendl_fd("pa", 1);
		}
		else
		{
			while (action->act_stack_a && action->act_stack_b)
			{
				do_operation(rotate_to_up, &(*stacks)->stack_a, "rr");
				do_operation(rotate_to_up, &(*stacks)->stack_b, NULL);
				action->act_stack_a--;
				action->act_stack_b--;
			}
			while (action->act_stack_a-- > 0)
				do_operation(rotate_to_up, &(*stacks)->stack_a, "ra");
			while (action->act_stack_b-- > 0)
				do_operation(rotate_to_up, &(*stacks)->stack_b, "rb");
			push(&(*stacks)->stack_b, &(*stacks)->stack_a);
			ft_putendl_fd("pa", 1);
		}
	}
	return (free(action), SUCCESS);
}
