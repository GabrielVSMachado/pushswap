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

int	number_of_ra(t_list *stack, const t_list *element)
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

int	find_the_next_and_prev_element(t_list *stack, int element,
		t_list **next, t_list **prev)
{
	int	*ord_array;
	int	index;

	ord_array = make_int_array(stack);
	if (!ord_array)
		return (ERROR);
	index = 0;
	while (ord_array[index] < element)
		index++;
	*prev = NULL;
	*next = NULL;
	while (stack)
	{
		if (*(int *)stack->content == ord_array[index])
			(*next) = stack;
		if (index - 1 >= 0 && *(int *)stack->content == ord_array[index - 1])
			(*prev) = stack;
		stack = stack->next;
	}
	free(ord_array);
	return (SUCCESS);
}

int	make_decision(t_stacks **stacks, int *len_chunck)
{
	t_list	*higher;
	t_list	*lower;
	int		n_ra[2];
	int		n_rra[2];

	ft_bzero(n_ra, sizeof(n_ra));
	ft_bzero(n_rra, sizeof(n_rra));
	if (find_the_next_and_prev_element((*stacks)->stack_a,
			*(int *)((*stacks)->stack_b->content), &higher, &lower) == ERROR)
		return (ERROR);
	if (lower && higher)
	{
		n_ra[0] = number_of_ra((*stacks)->stack_a, higher);
		n_rra[0] = number_of_rra((*stacks)->stack_a, higher);
		n_ra[1] = number_of_ra((*stacks)->stack_a, lower); 
		n_rra[1] = number_of_rra((*stacks)->stack_a, lower);
		n_rra[1]--;
		n_ra[1]++;
		if (n_ra[1] < n_ra[0])
			n_ra[0] = n_ra[1];
		if (n_rra[1] < n_rra[0])
			n_rra[0] = n_rra[1];
	}
	else if (higher)
	{
		n_ra[0] = number_of_ra((*stacks)->stack_a, higher);
		n_rra[0] = number_of_rra((*stacks)->stack_a, higher);
	}
	else if (lower)
	{
		n_ra[0] = number_of_ra((*stacks)->stack_a, lower); 
		n_rra[0] = number_of_rra((*stacks)->stack_a, lower);
	}
	if (n_ra[0] > n_rra[0])
		while (n_rra[0]-- > 0)
			do_operation(rotate_to_down, &(*stacks)->stack_a, "rra");
	else
		while (n_ra[0]-- > 0)
			do_operation(rotate_to_up, &(*stacks)->stack_a, "ra");
	push(&(*stacks)->stack_b, &(*stacks)->stack_a);
	ft_putendl_fd("pa", 1);
	(*len_chunck)--;
	return (SUCCESS);
}
