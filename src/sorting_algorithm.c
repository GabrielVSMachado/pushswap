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

int	*make_ints_array_from_llst(t_stacks **stacks, int len_chunck)
{
	int		*array;
	t_list	*llst_tmp;
	int		len_array;

	array = (int *)malloc(sizeof(int) * len_chunck);
	if (!array)
		exit(_error(*stacks));
	llst_tmp = (*stacks)->stack_b;
	len_array = len_chunck;
	while (len_chunck-- > 0)
	{
		array[len_chunck] = *(int *)llst_tmp->content;
		llst_tmp = llst_tmp->next;
	}
	quick_sort(array, 0, len_array - 1);
	return (array);
}

/* static void	sort_b(t_stacks	**stacks, t_list	*chunck_lenghts) */
/* { */
/* 	t_list	*tmp; */
/* 	int		*ord_array_tmp; */

/* 	tmp = chunck_lenghts; */
/* 	while ((*stacks)->stack_b) */
/* 	{ */
/* 		ord_array_tmp = make_ints_array_from_llst(stacks, */
/* 				*(int *)tmp->content); */
/* 		if (*(int *)tmp->content == 1) */
/* 		{ */
/* 			push(&(*stacks)->stack_b, &(*stacks)->stack_a); */
/* 			ft_putendl_fd("pa", 1); */
/* 		} */
/* 		else */
/* 			sort_chunck(&(*stacks)->stack_b, &(*stacks)->stack_a, *(int *)tmp->content); */
/* 	} */
/* } */

void	sorting(int **ord_array, t_stacks *stacks, int size_ord_array)
{
	int		*tmp;
	int		len;
	t_list	*chunck_lenghts;

	tmp = *ord_array;
	chunck_lenghts = NULL;
	while (stacks->stack_a != NULL && ft_lstsize(stacks->stack_a) > 2)
	{
		partition(&stacks->stack_a, &stacks->stack_b,
			tmp[(size_ord_array / 2)]);
		len = chunk_lenght(tmp[(size_ord_array / 2)], tmp);
		ft_lstadd_front(&chunck_lenghts, ft_lstnew(
				ft_memcpy(malloc(sizeof(int)), &len, sizeof(int))));
		tmp += len;
		size_ord_array -= len;
	}
	if (stacks->stack_a != NULL && !check_sorted(stacks->stack_a))
		do_operation(swap, &stacks->stack_a, "sa");
	free(*ord_array);
	ft_lstclear(&chunck_lenghts, free);
}
