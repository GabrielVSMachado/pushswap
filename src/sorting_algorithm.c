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

static int	sort_b(t_stacks	**stacks, int lower_element)
{
	t_list	tmp_lower;
	int		low[1];
	int		n_ra;
	int		n_rra;

	low[0] = lower_element;
	ft_bzero(&tmp_lower, sizeof(t_list));
	while ((*stacks)->stack_b)
		if (make_decision(stacks) == ERROR)
			return (ERROR);
	tmp_lower.content = low;
	n_ra = number_of_r((*stacks)->stack_a, &tmp_lower);
	n_rra = number_of_rr((*stacks)->stack_a, &tmp_lower);
	if (n_ra < n_rra)
	{
		while (!check_sorted((*stacks)->stack_a))
			do_operation(rotate_to_up, &(*stacks)->stack_a, "ra");
	}
	else
		while (!check_sorted((*stacks)->stack_a))
			do_operation(rotate_to_down, &(*stacks)->stack_a, "rra");
	return (SUCCESS);
}

int	sorting(int **ord_array, t_stacks *stacks, int size_ord_array)
{
	int		*tmp;
	int		len;
	int		lower_element;

	tmp = *ord_array;
	lower_element = tmp[0];
	while (ft_lstsize(stacks->stack_a) != 2)
	{
		partition(&stacks->stack_a, &stacks->stack_b,
			tmp[(size_ord_array / 2)], lower_element);
		len = chunk_lenght(tmp[(size_ord_array / 2)], tmp);
		tmp += len;
		size_ord_array -= len;
	}
	free(*ord_array);
	*ord_array = NULL;
	if (sort_b(&stacks, lower_element) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
