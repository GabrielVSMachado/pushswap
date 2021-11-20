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
# define ERROR -1
# define SUCCESS 1

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

/* FUNCTION TO HANDLE ERRORS OR CLEAR POINTERS*/
int		_error(t_stacks *stacks);
void	clear_stacks(t_stacks *stacks);

/* HELPERS FUNCTIONS TO SORTING ALGORITHM */
int		check_chunck_sorted_in_b(t_list *lst, int lenght);
int		less_than_mid_point(t_list *lst, int mid_point);
void	do_operation(int (*op)(), t_list **lst, const char *name_op);
void	partition(t_list **stack_from, t_list **stack_to, int mid_point);
int		chunk_lenght(int mid_point, int *array);
int		check_sorted(t_list *stack);
int		find_the_next_and_prev_element(t_list *stack, int element,
			t_list **next, t_list **prev);
int		index_of_element(t_list *lst, t_list *element);
int		number_of_ra(t_list *stack, const t_list *element);
int		number_of_rra(t_list *stack, const t_list *element);
int		make_decision(t_stacks **stacks, int *len_chunck);

/* FUNCTION TO EXECUTE SORTING */
int		sorting(int **ord_array, t_stacks *stacks, int size_ord_array);

/* FUNCTIONS QUICK_SORT*/
void	quick_sort(int	*array, int beginning, int end);

/* FUNCTIONS TO SETUP THE SORT */
void	setup_sorting(int argc, char **argv);
int		*make_int_array(t_list *stack);
int		*make_ints_array(int argc, char **argv);
#endif
