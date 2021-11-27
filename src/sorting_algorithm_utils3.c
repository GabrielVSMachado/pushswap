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

static void	setup_moviment(t_list *stack, t_list *element,
		struct s_moviments *movs)
{
	movs->n_ra = number_of_r(stack, element);
	movs->n_rra = number_of_rr(stack, element);
	if (movs->n_ra > movs->n_rra)
		movs->which_mov_lower = 1;
	else
		movs->which_mov_lower = 0;
}

static void	setup_all_moviments(t_stacks **stacks,
		struct s_calc_moviments *movs, int *ord_array, t_list *tmp_stack)
{
	t_list	*lower;

	setup_moviment((*stacks)->stack_b, tmp_stack, &movs->b_element);
	lower = find_element((*stacks)->stack_a, *(int *)tmp_stack->content,
			ord_array, cmp_lower);
	if (lower)
	{
		setup_moviment((*stacks)->stack_a, lower, &(movs->lower_b_element));
		movs->lower_b_element.n_ra++;
		movs->lower_b_element.n_rra--;
	}
	setup_moviment((*stacks)->stack_a, find_element((*stacks)->stack_a,
			*(int *)tmp_stack->content, ord_array, cmp_higher),
		&(movs->higher_than_b_element));
}

static struct s_moviments	*get_lesser_result(struct s_moviments *x,
		struct s_moviments *y)
{
	/* if (!y) */
	/* 	return (x); */
	if (x->which_mov_lower && y->which_mov_lower)
	{
		if (x->n_rra > y->n_rra)
			return (y);
		else
			return (x);
	}
	else if (!x->which_mov_lower && !y->which_mov_lower)
	{
		if (x->n_ra > y->n_ra)
			return (y);
		else
			return (x);
	}
	else if (!x->which_mov_lower && y->which_mov_lower)
	{
		if (x->n_ra > y->n_rra)
			return (y);
		else
			return (x);
	}
	else
		if (x->n_rra > y->n_ra)
			return (y);
	return (x);
}

/* calculate the element in b stack who will take the less actions to sort */
struct s_less_movs	*calculate_moviments(t_stacks **stacks)
{
	struct s_less_movs		*do_action;
	struct s_calc_moviments	tmp_movs;
	struct s_moviments		*lesser_tmp;
	t_list					*tmp_stack;
	int						*ord_array;
	int						current_value;
	int						prev_value;

	ord_array = make_int_array((*stacks)->stack_a);
	if (ord_array == NULL)
		return (NULL);
	do_action = (struct s_less_movs *)malloc(sizeof(struct s_less_movs));
	if (do_action == NULL)
		return (free(ord_array), NULL);
	ft_bzero(do_action, sizeof(struct s_less_movs));
	tmp_stack = (*stacks)->stack_b;
	prev_value = INT_MAX;
	while (tmp_stack != NULL)
	{
		ft_bzero(&tmp_movs, sizeof(struct s_calc_moviments));
		setup_all_moviments(stacks, &tmp_movs, ord_array, tmp_stack);
		lesser_tmp = get_lesser_result(&tmp_movs.higher_than_b_element,
				&tmp_movs.lower_b_element);
		if (lesser_tmp->which_mov_lower == tmp_movs.b_element.which_mov_lower)
		{
			if (!lesser_tmp->which_mov_lower
				&& !tmp_movs.b_element.which_mov_lower)
			{
				if (lesser_tmp->n_ra > tmp_movs.b_element.n_ra)
					current_value = lesser_tmp->n_ra;
				else
					current_value = tmp_movs.b_element.n_ra;
				if (prev_value > current_value)
				{
					prev_value = current_value;
					do_action->act_stack_a = lesser_tmp->n_ra;
					do_action->which_mov_a = lesser_tmp->which_mov_lower;
					do_action->act_stack_b = tmp_movs.b_element.n_ra;
					do_action->which_mov_b = tmp_movs.b_element.which_mov_lower;
				}
			}
			else
			{
				if (lesser_tmp->n_rra > tmp_movs.b_element.n_rra)
					current_value = lesser_tmp->n_rra;
				else
					current_value = tmp_movs.b_element.n_rra;
				if (prev_value > current_value)
				{
					prev_value = current_value;
					do_action->act_stack_a = lesser_tmp->n_rra;
					do_action->which_mov_a = lesser_tmp->which_mov_lower;
					do_action->act_stack_b = tmp_movs.b_element.n_rra;
					do_action->which_mov_b = tmp_movs.b_element.which_mov_lower;
				}
			}
		}
		else
		{
			if (!lesser_tmp->which_mov_lower
				&& tmp_movs.b_element.which_mov_lower)
			{
				current_value = lesser_tmp->n_ra + tmp_movs.b_element.n_rra;
				if (prev_value > current_value)
				{
					prev_value = current_value;
					do_action->act_stack_a = lesser_tmp->n_ra;
					do_action->which_mov_a = lesser_tmp->which_mov_lower;
					do_action->act_stack_b = tmp_movs.b_element.n_rra;
					do_action->which_mov_b = tmp_movs.b_element.which_mov_lower;
				}
			}
			else
			{
				current_value = lesser_tmp->n_rra + tmp_movs.b_element.n_ra;
				if (prev_value > current_value)
				{
					prev_value = current_value;
					do_action->act_stack_a = lesser_tmp->n_rra;
					do_action->which_mov_a = lesser_tmp->which_mov_lower;
					do_action->act_stack_b = tmp_movs.b_element.n_ra;
					do_action->which_mov_b = tmp_movs.b_element.which_mov_lower;
				}
			}
		}
		tmp_stack = tmp_stack->next;
	}
	return (free(ord_array), do_action);
}
