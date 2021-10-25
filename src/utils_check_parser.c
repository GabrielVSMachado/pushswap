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
