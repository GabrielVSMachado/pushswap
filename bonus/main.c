/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:35:30 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/28 20:35:30 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	write(1, argv[1], ft_strlen(argv[1]));
	return (EXIT_SUCCESS);
}
