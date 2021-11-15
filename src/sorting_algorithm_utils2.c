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

t_list	*find_the_higher_element_in_lst(t_list *lst)
{
	t_list	*high_element;

	high_element = lst;
	while (lst)
	{
		if (*(int *)lst->content > *(int *)high_element->content)
			high_element = lst;
		lst = lst->next;
	}
	return (high_element);
}

int	index_of_high_element(t_list *lst, t_list *high)
{
	int	index;
	int	size;

	index = 0;
	size = ft_lstsize(lst);
	while (lst != high)
	{
		lst = lst->next;
		index++;
	}
	if (index > size / 2)
		index -= size;
	return (index);
}
