/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:13:41 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/10/04 15:13:41 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_list	*make_lst(char **numbers, int len)
{
	t_list	*head;
	int		*tmp;
	int		n_args;

	n_args = 1;
	head = NULL;
	while (n_args < len)
	{
		tmp = (int *)malloc(sizeof(int));
		*tmp = ft_atoi(numbers[n_args]);
		ft_lstadd_back(&head, ft_lstnew(tmp));
		n_args++;
	}
	return (head);
}

static int	equals(char **numbers, int len)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*tmp_2;

	head = make_lst(numbers, len);
	if (!head)
		return (ft_lstclear(&head, free), 1);
	tmp = head;
	while (tmp)
	{
		tmp_2 = tmp->next;
		while (tmp_2)
		{
			if (*(int *)tmp->content == *(int *)tmp_2->content)
				return (ft_lstclear(&head, free), 1);
			tmp_2 = tmp_2->next;
		}
		tmp = tmp->next;
	}
	return (ft_lstclear(&head, free), 0);
}

int	validated_inputs(char **inputs, int len)
{
	int		n_args;
	char	*tmp;

	n_args = 1;
	while (n_args < len)
	{
		tmp = inputs[n_args];
		if (!*tmp)
			return (1);
		while (*tmp)
		{
			if ((*tmp != '-' || *tmp != '+') && !ft_isdigit(*tmp))
				return (1);
			tmp++;
		}
		n_args++;
	}
	if (equals(inputs, len))
		return (1);
	return (0);
}
