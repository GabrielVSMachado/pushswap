/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:51:48 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/27 17:51:48 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putendl_fd("Error", 2);
		exit(_error(NULL));
	}
	if (check_isdigit(argc, argv) || check_repeated(argc, argv)
		|| check_greater_than_max_or_less_than_min_int(argc, argv))
	{
		ft_putendl_fd("Error", 2);
		exit(_error(NULL));
	}
	setup_sorting(argc, argv);
	return (EXIT_SUCCESS);
}
