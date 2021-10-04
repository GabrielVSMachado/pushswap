/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:37:00 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/28 20:37:00 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

int		validated_inputs(char **inputs, int len);
t_list	*make_lst(char **numbers, int len);

#endif
