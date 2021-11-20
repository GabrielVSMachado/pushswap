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

static int	sort_highers_chuncks(t_stacks **stacks, int *len_chunck)
{
	if (*(int *)((*stacks)->stack_b->content)
			== *(int *)((*stacks)->stack_a->content) - 1)
	{
		push(&(*stacks)->stack_b, &(*stacks)->stack_a);
		ft_putendl_fd("pa", 1);
	}
	else
		if (make_decision(stacks, len_chunck) == ERROR)
			return (ERROR);
	return (SUCCESS);
}

static int	sort_chunck(t_stacks **stacks, int len_chunck)
{
	while (len_chunck)
	{
		/* if (len_chunck <= 2) */
		/* { */
		/* 	if (!check_chunck_sorted_in_b((*stacks)->stack_b, len_chunck)) */
		/* 		do_operation(swap, &(*stacks)->stack_b, "sb"); */
		/* 	while (len_chunck > 0) */
		/* 	{ */
		/* 		push(&(*stacks)->stack_b, &(*stacks)->stack_a); */
		/* 		ft_putendl_fd("pa", 1); */
		/* 		len_chunck--; */
		/* 	} */
		/* } */
		/* else */
		if (sort_highers_chuncks(stacks, &len_chunck) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	sort_b(t_stacks	**stacks, t_list *len_chunck)
{
	t_list			*tmp;

	tmp = len_chunck;
	while ((*stacks)->stack_b)
	{
		/* if (*(int *)tmp->content == 1 */
		/* 	|| check_chunck_sorted_in_b((*stacks)->stack_b, */
		/* 		*(int *)tmp->content)) */
		/* { */
		/* 	while ((*(int *)tmp->content)-- > 0) */
		/* 	{ */
		/* 		push(&(*stacks)->stack_b, &(*stacks)->stack_a); */
		/* 		ft_putendl_fd("pa", 1); */
		/* 	} */
		/* } */
		if (sort_chunck(stacks, *(int *)tmp->content) == ERROR)
			return (ERROR);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int	sorting(int **ord_array, t_stacks *stacks, int size_ord_array)
{
	int		*tmp;
	int		len;
	t_list	*chunck_lenghts;

	tmp = *ord_array;
	chunck_lenghts = NULL;
	if (size_ord_array == 1)
		ft_putendl_fd("1", 1);
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
	if (sort_b(&stacks, chunck_lenghts) == ERROR)
		return (ft_lstclear(&chunck_lenghts, free), ERROR);
	ft_lstclear(&chunck_lenghts, free);
	return (SUCCESS);
}
