/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_utils2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:26:20 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/14 09:26:20 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	*make_int_array(t_stacks **stacks, int len_chunck)
{
	t_list	*llst_tmp;
	int		len_ord_array;
	int		*ord_array;

	ord_array = (int *)malloc(sizeof(int) * len_chunck);
	if (!ord_array)
		exit(_error(*stacks));
	llst_tmp = (*stacks)->stack_b;
	len_ord_array = len_chunck;
	while (len_chunck-- > 0)
	{
		(ord_array)[len_chunck] = *(int *)llst_tmp->content;
		llst_tmp = llst_tmp->next;
	}
	quick_sort(ord_array, 0, len_ord_array - 1);
	return (ord_array);
}

t_list	*find_element(t_list *lst, int element, int op)
{
	t_list	*tmp[2];
	int		counter;

	tmp[0] = lst;
	counter = op;
	while (tmp[0])
	{
		tmp[1] = lst;
		while (tmp[1])
		{
			if (*(int *)(tmp[1])->content + counter == element)
				return (tmp[1]);
			tmp[1] = (tmp[1])->next;
		}
		counter += op;
		tmp[0] = (tmp[0])->next;
	}
	return (NULL);
}

int	index_of_element(t_list *lst, t_list *element)
{
	int	index;
	int	size;

	index = 0;
	size = ft_lstsize(lst);
	while (lst != element)
	{
		lst = lst->next;
		index++;
	}
	if (index > size / 2)
		index -= size;
	return (index);
}

void	make_decision(t_list **stack_a, int element)
{
	t_list	*higher;
	t_list	*lower;
	int		n_ra[2];
	int		n_rra[2];

	ft_bzero(&n_ra, sizeof(int) * 2);
	ft_bzero(&n_rra, sizeof(int) * 2);
	higher = find_element(*stack_a, element, -1);
	lower = find_element(*stack_a, element, +1);
	if (higher)
	{
		n_ra[0] = number_of_op(*stack_a, higher, rotate_to_up);
		n_rra[0] = number_of_op(*stack_a, higher, rotate_to_down);
	}
	if (lower)
	{
		n_ra[1] = number_of_op(*stack_a, lower, rotate_to_up);
		n_rra[1] = number_of_op(*stack_a, lower, rotate_to_down);
	}
}
