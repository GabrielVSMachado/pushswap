/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_do_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:09:36 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/28 10:09:36 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setup_do_action_which_movs_equals(struct s_less_movs *do_action,
		struct s_moviments *movs_a, struct s_moviments *movs_b,
		struct s_norminette *values)
{
	if (values->prev_value > values->current_value)
	{
		values->prev_value = values->current_value;
		if (movs_a->which_mov_lower == 1 && movs_b->which_mov_lower == 1)
		{
			do_action->act_stack_a = movs_a->n_rr;
			do_action->act_stack_b = movs_b->n_rr;
			do_action->which_mov_a = 1;
			do_action->which_mov_b = 1;
		}
		else
		{
			do_action->act_stack_a = movs_a->n_r;
			do_action->act_stack_b = movs_b->n_r;
			do_action->which_mov_a = 0;
			do_action->which_mov_b = 0;
		}
	}
}

static void	setup_do_action_which_movs_unequal(struct s_less_movs *do_action,
		struct s_moviments *movs_a, struct s_moviments *movs_b,
		struct s_norminette *values)
{
	if (movs_a->which_mov_lower == 0 && movs_b->which_mov_lower == 1)
		values->current_value = movs_a->n_r + movs_b->n_rr;
	else
		values->current_value = movs_a->n_rr + movs_b->n_r;
	if (values->prev_value > values->current_value)
	{
		values->prev_value = values->current_value;
		if (movs_a->which_mov_lower == 0 && movs_b->which_mov_lower == 1)
		{
			do_action->act_stack_a = movs_a->n_r;
			do_action->act_stack_b = movs_b->n_rr;
			do_action->which_mov_a = 0;
			do_action->which_mov_b = 1;
		}
		else
		{
			do_action->act_stack_a = movs_a->n_rr;
			do_action->act_stack_b = movs_b->n_r;
			do_action->which_mov_a = 1;
			do_action->which_mov_b = 0;
		}
	}
}

void	compare_movs(struct s_less_movs *action, struct s_moviments *movs_a,
		struct s_moviments *movs_b, struct s_norminette *values)
{
	if (!movs_a->which_mov_lower && !movs_b->which_mov_lower)
	{
		values->current_value = movs_b->n_r;
		if (movs_a->n_r > movs_b->n_r)
			values->current_value = movs_a->n_r;
		setup_do_action_which_movs_equals(action, movs_a,
			movs_b, values);
	}
	else if (movs_a->which_mov_lower && movs_b->which_mov_lower)
	{
		values->current_value = movs_b->n_rr;
		if (movs_a->n_rr > movs_b->n_rr)
			values->current_value = movs_a->n_rr;
		setup_do_action_which_movs_equals(action, movs_a,
			movs_b, values);
	}
	else if (!movs_a->which_mov_lower && movs_b->which_mov_lower)
		setup_do_action_which_movs_unequal(action, movs_a,
			movs_b, values);
	else
		setup_do_action_which_movs_unequal(action, movs_a,
			movs_b, values);
}
