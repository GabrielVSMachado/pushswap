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

static void	sort_b(t_stacks	**stacks, t_list *len_chunk)
{
	t_list		*tmp;
	/* int			*ord_array_tmp; */

	tmp = len_chunk;
	while ((*stacks)->stack_b && tmp)
	{
		if (*(int *)tmp->content == 1
			|| check_chunck_sorted_in_b((*stacks)->stack_b,
				*(int *)tmp->content))
		{
			while ((*(int *)tmp->content)-- > 0)
			{
				push(&(*stacks)->stack_b, &(*stacks)->stack_a);
				ft_putendl_fd("pa", 1);
			}
		}
		/* else */
		/* { */
		/* 	ord_array_tmp = make_ints_array_from_llst(stacks, */
		/* 			*(int *)tmp->content); */
		/* 	sort_chunck(&(*stacks)->stack_b, &(*stacks)->stack_a, */
		/* 		*(int *)tmp->content, ord_array_tmp); */
		/* } */
		tmp = tmp->next;
	}
}

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
	sort_b(&stacks, chunck_lenghts);
	free(*ord_array);
	ft_lstclear(&chunck_lenghts, free);
}
