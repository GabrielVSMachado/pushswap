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
# define INT_MAX 0x7FFFFFFF

# include "libft.h"

struct s_norminette
{
	int	prev_value;
	int	current_value;
};

typedef struct s_less_movs
{
	int				act_stack_a;
	int				act_stack_b;
	unsigned int	which_mov_a:1;
	unsigned int	which_mov_b:1;
}	t_less;

struct s_moviments
{
	int				n_r;
	int				n_rr;
	unsigned int	which_mov_lower:1;
};

struct s_calc_moviments
{
	struct s_moviments	lower_b_element;
	struct s_moviments	higher_than_b_element;
	struct s_moviments	b_element;
};

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
int		less_than_mid_point(t_list *lst, int mid_point, int lower);
int		chunk_lenght(int mid_point, int *array);
int		check_sorted(t_list *stack);
int		index_of_element(t_list *lst, t_list *element);
int		number_of_r(t_list *stack, int element);
int		number_of_rr(t_list *stack, int element);
int		make_decision(t_stacks **stacks);
void	do_operation(int (*op)(), t_list **lst, const char *name_op);
void	partition(t_list **stack_from, t_list **stack_to, int mid_point,
			int lower);
t_list	*find_element(t_list *stack, int element,
			int *ord_array, int (*cmp)(int, int, int*));
void	calculate_moviments(t_stacks **stacks, int *ord_array,
			struct s_less_movs *action);
void	exec_action(struct s_less_movs *action, t_stacks **stacks);
void	compare_movs(struct s_less_movs *action, struct s_moviments *movs_a,
			struct s_moviments *movs_b, struct s_norminette *values);

/* FUNCTIONS TO COMPARE IN FUNCTION FIND_ELEMENT */
int		cmp_lower(int element, int index, int *ord_array);
int		cmp_higher(int element, int index, int *ord_array);

/* FUNCTION TO EXECUTE SORTING */
int		sorting(int **ord_array, t_stacks *stacks, int size_ord_array);

/* FUNCTIONS QUICK_SORT*/
void	quick_sort(int	*array, int beginning, int end);

/* FUNCTIONS TO SETUP THE SORT */
void	setup_sorting(int argc, char **argv);
int		*make_int_array(t_list *stack);
int		*make_ints_array(int argc, char **argv);
#endif
