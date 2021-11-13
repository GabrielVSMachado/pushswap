/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:48:21 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/11/05 08:48:21 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**make_ints_array(int argc, char **argv)
{
	int	**num;
	int	counter;

	num = (int **)malloc(sizeof(int *) * --argc);
	ft_bzero(num, sizeof(num));
	counter = 0;
	while (counter < argc)
	{
		num[counter] = (int *)malloc(sizeof(int));
		*num[counter] = ft_atoi(argv[counter + 1]);
		counter++;
	}
	return (num);
}

static void	swap_q(int **a, int **b)
{
	int	tmp;

	tmp = **a;
	**a = **b;
	**b = tmp;
}

static int	paritition_quick(int **array, int beginning, int end)
{
	int	pivot;
	int	counter_i;
	int	counter_j;

	counter_i = beginning;
	counter_j = beginning;
	pivot = *array[end];
	while (counter_j < end)
	{
		if (*array[counter_j] < pivot)
		{
			swap_q(&array[counter_j], &array[counter_i]);
			counter_i++;
		}
		counter_j++;
	}
	swap_q(&array[end], &array[counter_i]);
	return (counter_i);
}

void	quick_sort(int	**array, int beginning, int end)
{
	int	mid_point;

	if (beginning < end)
	{
		mid_point = paritition_quick(array, beginning, end);
		quick_sort(array, beginning, mid_point - 1);
		quick_sort(array, mid_point + 1, end);
	}
}
