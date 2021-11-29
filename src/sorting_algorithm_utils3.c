/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_utils3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:22:29 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/27 17:22:29 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setup_moviment(t_list *stack, int element,
		struct s_moviments *movs)
{
	movs->n_r = number_of_r(stack, element);
	movs->n_rr = number_of_rr(stack, element);
	if (movs->n_r > movs->n_rr)
		movs->which_mov_lower = 1;
	else
		movs->which_mov_lower = 0;
}

static void	setup_all_moviments(t_stacks **stacks,
		struct s_calc_moviments *movs, int *ord_array, t_list *tmp_stack)
{
	t_list	*lower_than_b_element;
	t_list	*higher_than_b_element;

	lower_than_b_element = find_element((*stacks)->stack_a,
			*(int *)tmp_stack->content, ord_array, cmp_lower);
	higher_than_b_element = find_element((*stacks)->stack_a,
			*(int *)tmp_stack->content, ord_array, cmp_higher);
	setup_moviment((*stacks)->stack_b, *(int *)tmp_stack->content,
		&movs->b_element);
	setup_moviment((*stacks)->stack_a, *(int *)lower_than_b_element->content,
		&(movs->lower_b_element));
	movs->lower_b_element.n_r++;
	movs->lower_b_element.n_rr--;
	setup_moviment((*stacks)->stack_a, *(int *)higher_than_b_element->content,
		&(movs->higher_than_b_element));
}

static struct s_moviments	*get_lesser_result(struct s_moviments *x,
		struct s_moviments *y)
{
	if (x->which_mov_lower && y->which_mov_lower)
	{
		if (x->n_rr > y->n_rr)
			return (y);
		else
			return (x);
	}
	else if (!x->which_mov_lower && !y->which_mov_lower)
	{
		if (x->n_r > y->n_r)
			return (y);
		else
			return (x);
	}
	else if (!x->which_mov_lower && y->which_mov_lower)
	{
		if (x->n_r > y->n_rr)
			return (y);
		else
			return (x);
	}
	else
		if (x->n_rr > y->n_r)
			return (y);
	return (x);
}

/* calculate the element in b stack who will take the less actions to sort */
void	calculate_moviments(t_stacks **stacks, int *ord_array,
				struct s_less_movs *do_action)
{
	struct s_calc_moviments	tmp_movs;
	struct s_moviments		*lesser_tmp;
	struct s_norminette		values;
	t_list					*tmp_stack;

	ft_bzero(&tmp_movs, sizeof(struct s_calc_moviments));
	tmp_stack = (*stacks)->stack_b;
	values.prev_value = INT_MAX;
	while (tmp_stack != NULL)
	{
		setup_all_moviments(stacks, &tmp_movs, ord_array, tmp_stack);
		lesser_tmp = get_lesser_result(&tmp_movs.higher_than_b_element,
				&tmp_movs.lower_b_element);
		compare_movs(do_action, lesser_tmp, &tmp_movs.b_element, &values);
		tmp_stack = tmp_stack->next;
	}
}
