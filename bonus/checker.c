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

static void	exec_movement(int (*f)(), int action, struct s_stacks *s)
{
	if (action == 1)
		(*f)(&s->stack_a);
	else if (action == 0)
		(*f)(&s->stack_b);
	else if (action == 2)
	{
		(*f)(&s->stack_a);
		(*f)(&s->stack_b);
	}
	else if (action == 3)
		(*f)(&s->stack_b, &s->stack_a);
	else if (action == 4)
		(*f)(&s->stack_a, &s->stack_b);
}

static int	check_sorting_lst(struct s_stacks *s)
{
	t_list	*tmp;

	if (s->stack_b != NULL)
		return (1);
	tmp = s->stack_a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
		{
			ft_lstclear(&s->stack_a, free);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_lstclear(&s->stack_a, free);
	return (0);
}

static int	checker_valid_movement(struct s_stacks *s, char *movement)
{
	if (!ft_strcmp("ss", movement))
		exec_movement(&swap, 2, s);
	else if (!ft_strcmp("sa", movement) || !ft_strcmp("sb", movement))
		exec_movement(&swap, movement[1] == 'a', s);
	else if (!ft_strcmp("pa", movement))
		exec_movement(&push, 3, s);
	else if (!ft_strcmp("pb", movement))
		exec_movement(&push, 4, s);
	else if (!ft_strcmp("rr", movement))
		exec_movement(&rotate_to_up, 2, s);
	else if (!ft_strcmp("ra", movement) || !ft_strcmp("rb", movement))
		exec_movement(&rotate_to_up, movement[1] == 'a', s);
	else if (!ft_strcmp("rrr", movement))
		exec_movement(&rotate_to_down, 2, s);
	else if (!ft_strcmp("rra", movement) || !ft_strcmp("rrb", movement))
		exec_movement(&rotate_to_down, movement[2] == 'a', s);
	else
		return (1);
	return (0);
}

static void	init_checker(int size_array, char **numbers_as_str)
{
	struct s_stacks	s;
	char			*movement;

	s.stack_a = make_llst_of_ints(size_array, numbers_as_str);
	s.stack_b = NULL;
	while (get_next_line(0, &movement) > 0)
	{
		if (checker_valid_movement(&s, movement))
		{
			write(2, "Error", 5);
			exit(EXIT_FAILURE);
		}
		print_stack(&s.stack_a, 'a');
		print_stack(&s.stack_b, 'b');
		free(movement);
	}
	if (check_sorting_lst(&s))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(movement);
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
