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

static void	sort_highers_chuncks(t_list **from, t_list **to, int len_chunck)
{
	int		n_ra;
	t_list	*high_element;

	n_ra = 0;
	while (len_chunck)
	{
		high_element = find_the_higher_element_in_lst(*from);
		if ((*from) == high_element)
		{
			push(from, to);
			ft_putendl_fd("pa", 1);
			(len_chunck)--;
			while (n_ra != 0)
			{
				high_element = find_the_higher_element_in_lst(*from);
				if (high_element == (*from))
				{
					push(from, to);
					ft_putendl_fd("pa", 1);
					(len_chunck)--;
				}
				do_operation(rotate_to_down, from, "rrb");
				n_ra--;
			}
		}
		else if ((*from)->next == high_element)
			do_operation(swap, from, "sb");
		else
		{
			do_operation(rotate_to_up, from, "rb");
			n_ra++;
		}
	}
}

static void	sort_chunck(t_list **from, t_list **to, int len_chunck)
{
	if (len_chunck == 2 && !check_chunck_sorted_in_b(*from, len_chunck))
	{
		do_operation(swap, from, "sb");
		while (len_chunck-- > 0)
		{
			push(from, to);
			ft_putendl_fd("pa", 1);
		}
	}
	else
		sort_highers_chuncks(from, to, len_chunck);
}

static void	sort_b(t_stacks	**stacks, t_list *len_chunk)
{
	t_list		*tmp;

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
		else
		{
			sort_chunck(&(*stacks)->stack_b, &(*stacks)->stack_a,
				*(int *)tmp->content);
		}
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
