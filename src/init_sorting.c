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

int	chunk_lenght(int mid_point, int **array)
{
	int	lenght;

	lenght = 0;
	while (*array[lenght] != mid_point)
		lenght++;
	return (lenght);
}

/* void	init_sorting(int argc, char **argv) */
/* { */
/* 	t_stacks	stacks; */
/* 	int			**ord_array; */
/* 	int			mid_point; */

/* 	ft_bzero(&stacks, sizeof(t_stacks)); */
/* 	stacks.stack_a = make_llst_of_ints(argc, argv); */
/* 	ord_array = make_ints_array(argc, argv); */
/* 	quick_sort(ord_array, 0, (sizeof(ord_array) / 4) - 1); */
/* 	mid_point = *ord_array[(sizeof(ord_array) / 4) / 2]; */
/* } */
