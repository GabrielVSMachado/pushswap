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

t_list	*make_lst(char **numbers, int len)
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

int	validated_inputs(char **inputs, int len)
{
}
