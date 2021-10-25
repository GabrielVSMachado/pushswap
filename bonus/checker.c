/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:18:02 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/10/04 11:18:02 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static void	print_stack(t_list **stack, char name_stack)
{
	t_list	*ptr_lst;

	ptr_lst = *stack;
	printf("%c|", name_stack);
	while (ptr_lst)
	{
		printf("%d ", *(int *)ptr_lst->content);
		ptr_lst = ptr_lst->next;
	}
	printf("\n");
}

static int	init_checker(int size_array, char **numbers_as_str)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*movement;

	stack_a = make_llst_of_ints(size_array, numbers_as_str);
	stack_b = NULL;
	while (get_next_line(0, &movement) > 0)
	{
		if (!ft_strcmp("sa", movement))
			swap(&stack_a);
		else if (!ft_strcmp("sb", movement))
			swap(&stack_b);
		else if (!ft_strcmp("ss", movement))
		{
			swap(&stack_a);
			swap(&stack_b);
		}
		else if (!ft_strcmp("pa", movement))
			push(&stack_b, &stack_a);
		else if (!ft_strcmp("pb", movement))
			push(&stack_a, &stack_b);
		else if (!ft_strcmp("ra", movement))
			rotate_to_up(&stack_a);
		else if (!ft_strcmp("rb", movement))
			rotate_to_up(&stack_b);
		else if (!ft_strcmp("rr", movement))
		{
			rotate_to_up(&stack_a);
			rotate_to_up(&stack_b);
		}
		else if (!ft_strcmp("rra", movement))
			rotate_to_down(&stack_a);
		else if (!ft_strcmp("rrb", movement))
			rotate_to_down(&stack_b);
		else if (!ft_strcmp("rrr", movement))
		{
			rotate_to_down(&stack_a);
			rotate_to_down(&stack_b);
		}
		else
		{
			write(2, "Error", 5);
			exit (EXIT_FAILURE);
		}
		print_stack(&stack_a, 'a');
		print_stack(&stack_b, 'b');
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (check_isdigit(argc, argv)
		|| check_greater_than_max_or_less_than_min_int(argc, argv)
		||check_repeated(argc, argv))
	{
		write(2, "Error", 5);
		exit(EXIT_FAILURE);
	}
	init_checker(argc, argv);
	return (EXIT_SUCCESS);
}
