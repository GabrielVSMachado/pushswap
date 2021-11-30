/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:37:36 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/08 18:37:36 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stacks *stacks, int *ord_array)
{
	if (*(int *)ft_lstlast((stacks)->stack_a)->content == ord_array[2])
		do_operation(swap, &(stacks)->stack_a, "sa");
	else if (*(int *)ft_lstlast((stacks)->stack_a)->content == ord_array[1])
	{
		if (*(int *)(stacks)->stack_a->content == ord_array[0])
		{
			do_operation(rotate_to_down, &(stacks)->stack_a, "rra");
			do_operation(swap, &(stacks)->stack_a, "sa");
		}
		else
			do_operation(rotate_to_up, &(stacks)->stack_a, "ra");
	}
	else
	{
		if (*(int *)(stacks)->stack_a->content == ord_array[2])
		{
			do_operation(swap, &(stacks)->stack_a, "sa");
			do_operation(rotate_to_down, &(stacks)->stack_a, "rra");
		}
		else
			do_operation(rotate_to_down, &(stacks)->stack_a, "rra");
	}
}

static void	put_lower_element_on_top(int lower_element, t_stacks **stacks)
{
	int		n_ra;
	int		n_rra;

	n_ra = number_of_r((*stacks)->stack_a, lower_element);
	n_rra = number_of_rr((*stacks)->stack_a, lower_element);
	if (n_ra < n_rra)
	{
		while (!check_sorted((*stacks)->stack_a))
			do_operation(rotate_to_up, &(*stacks)->stack_a, "ra");
	}
	else
		while (!check_sorted((*stacks)->stack_a))
			do_operation(rotate_to_down, &(*stacks)->stack_a, "rra");
}

static int	sort_b(t_stacks	**stacks, int lower_element)
{
	while ((*stacks)->stack_b)
	{
		if (make_decision(stacks) == ERROR)
			return (ERROR);
	}
	put_lower_element_on_top(lower_element, stacks);
	return (SUCCESS);
}

int	sorting(int **ord_array, t_stacks *stacks, int size_ord_array)
{
	int		*tmp;
	int		len;
	int		lower_element;

	tmp = *ord_array;
	lower_element = tmp[0];
	while (ft_lstsize(stacks->stack_a) > 3)
	{
		partition(&stacks->stack_a, &stacks->stack_b,
			tmp[(size_ord_array / 3)], lower_element);
		len = chunk_lenght(tmp[(size_ord_array / 3)], tmp);
		tmp += len;
		size_ord_array -= len;
	}
	tmp = make_int_array(stacks->stack_a);
	if (!check_sorted(stacks->stack_a))
		sort_three_elements(stacks, tmp);
	free(tmp);
	if (sort_b(&stacks, lower_element) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
