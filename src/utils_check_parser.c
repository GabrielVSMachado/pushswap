/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:43:09 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/10/21 18:43:09 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isdigit(int argc, char **argv)
{
	int		chr_position;

	while (--argc)
	{
		if (!argv[argc][0])
			return (1);
		chr_position = -1;
		while (argv[argc][++chr_position])
		{
			if (argv[argc][chr_position] == '-' && chr_position == 0)
				continue ;
			if (!ft_isdigit(argv[argc][chr_position]))
				return (1);
		}
	}
	return (0);
}

int	check_repeated(int argc, char **argv)
{
	int	next_ptr;

	while (--argc)
	{
		next_ptr = argc;
		while (--next_ptr)
			if (!ft_strcmp(argv[argc], argv[next_ptr]))
				return (1);
	}
	return (0);
}

int	check_greater_than_max_or_less_than_min_int(int argc, char **argv)
{
	int	len_str_num;

	while (--argc)
	{
		len_str_num = ft_strlen(argv[argc]);
		if (len_str_num < 10)
			continue ;
		else
			if ((len_str_num == 10 && argv[argc][len_str_num - 1] != '7')
				|| (len_str_num == 11 && argv[argc][len_str_num - 1] != '8'))
				return (1);
	}
	return (0);
}

t_list	*make_llst_of_ints(int size, char **numbers_as_strings)
{
	t_list	*head;
	int		*tmp;

	head = NULL;
	while (--size)
	{
		tmp = (int *)malloc(sizeof(int));
		*tmp = ft_atoi(numbers_as_strings[size]);
		ft_lstadd_front(&head, ft_lstnew(tmp));
	}
	tmp = NULL;
	return (head);
}
