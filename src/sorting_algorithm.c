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

static int	check_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sorting(int **ord_array, t_stacks *stacks, int size_ord_array)
{
	int		**tmp;
	int		len;
	t_list	*chunck_lenghts;

	tmp = ord_array;
	chunck_lenghts = NULL;
	while (stacks->stack_a != NULL && ft_lstsize(stacks->stack_a) > 2)
	{
		partition(&stacks->stack_a, &stacks->stack_b,
			*tmp[(size_ord_array / 2)]);
		len = chunk_lenght(*tmp[(size_ord_array / 2)], tmp);
		ft_lstadd_front(&chunck_lenghts, ft_lstnew(
				ft_memcpy(malloc(sizeof(int)), &len, sizeof(int))));
		tmp += len;
		size_ord_array -= len;
	}
	if (stacks->stack_a != NULL && !check_sorted(stacks->stack_a))
		do_operation(swap, &stacks->stack_a, "sa");
	ft_lstclear(&chunck_lenghts, free);
}
