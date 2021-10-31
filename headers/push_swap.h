/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:54:53 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/09/27 17:54:53 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define LEN_MIN_INT 11

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stacks;

/* MOVIMENT FUNCTIONS */
int		swap(t_list **lst);
int		push(t_list **from, t_list **to);
int		rotate_to_up(t_list **stack);
int		rotate_to_down(t_list **stack);

/* FUNCTIONS TO CHECK INPUT */
int		check_isdigit(int argc, char **argv);
int		check_repeated(int argc, char **argv);
int		check_greater_than_max_or_less_than_min_int(int argc, char **argv);

/* FUNCTIONS TO MAKE A LINKED LIST WITH THE INPUTS */
t_list	*make_llst_of_ints(int size, char **numbers_as_strings);

/* FUNCTION TO HANDLE ERRORS */
int		_error(t_stacks *stacks);
void	clear_stacks(t_stacks *stacks);
#endif
