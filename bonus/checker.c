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

int	main(int argc, char *argv[])
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (validated_inputs(argv, argc))
		write(2, "Error", 5);
	else
		write(1, "OK", 2);
	return (EXIT_SUCCESS);
}
