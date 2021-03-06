/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:38:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/06 16:38:02 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup_sorting(int argc, char **argv)
{
	t_stacks	stacks;
	int			*ord_array;

	ft_bzero(&stacks, sizeof(t_stacks));
	stacks.stack_a = make_llst_of_ints(argc, argv);
	ord_array = make_ints_array(argc, argv);
	quick_sort(ord_array, 0, argc - 2);
	if (!check_sorted(stacks.stack_a))
	{
		if (ft_lstsize(stacks.stack_a) == 3)
			sort_three_elements(&stacks, ord_array);
		else if (sorting(&ord_array, &stacks, argc - 1) == ERROR)
			exit(_error(&stacks));
	}
	free(ord_array);
	clear_stacks(&stacks);
}
