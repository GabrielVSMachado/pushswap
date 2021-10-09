#include "minunit.h"
#include "push_swap.h"

MU_TEST(test_swap_two_integers)
{
	t_list	*head;
	int		*tmp;

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew((void *)0));
	ft_lstadd_back(&head, ft_lstnew((void *)1));
	mu_assert_int_eq(0, head->content);
	mu_assert_int_eq(1, head->next->content);
	swap(&head);
	mu_assert_int_eq(0, head->next->content);
	mu_assert_int_eq(1, head->content);
	free(head->next->content);
	free(head->next);
	free(head);
	head = NULL;
}

MU_TEST_SUITE(test_suite_swap)
{
	MU_RUN_TEST(test_swap_two_integers);
}


int	main(int argc, char *argv[])
{
	MU_RUN_SUITE(test_suite_swap);
	MU_REPORT();
	return MU_EXIT_CODE;
}
