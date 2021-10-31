/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:15:17 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/10/29 10:15:17 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_error(t_stacks *stacks)
{
	clear_stacks(stacks);
	return (EXIT_FAILURE);
}

void	clear_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->stack_b)
			ft_lstclear(&stacks->stack_b, free);
		if (stacks->stack_a)
			ft_lstclear(&stacks->stack_a, free);
	}
}
