#include "minunit.h"
#include "push_swap.h"

MU_TEST(test_swap_two_integers)
{
	t_list	*head;

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew((void *)0));
	ft_lstadd_back(&head, ft_lstnew((void *)1));
	mu_assert_int_eq(0, head->content);
	mu_assert_int_eq(1, head->next->content);
	mu_check(swap(&head) == 0);
	mu_assert_int_eq(0, head->next->content);
	mu_assert_int_eq(1, head->content);
	free(head->next->content);
	free(head->next);
	free(head);
	head = NULL;
}

MU_TEST(test_swap_with_one_number_and_second_null)
{
	t_list	*head;

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew((void *)1));
	mu_assert_int_eq(1, head->content);
	mu_check(head->next == NULL);
	mu_check(swap(&head) == 1);
	mu_assert_int_eq(1, head->content);
	mu_check(head->next == NULL);
	free(head);
	head = NULL;
}

MU_TEST_SUITE(test_suite_swap)
{
	MU_RUN_TEST(test_swap_two_integers);
	MU_RUN_TEST(test_swap_with_one_number_and_second_null);
}


MU_TEST(test_push_one_number_from_a_to_b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	ft_lstadd_back(&head_a, ft_lstnew((void *)1));
	ft_lstadd_back(&head_a, ft_lstnew((void *)2));

	mu_assert_int_eq(1, head_a->content);
	mu_assert_int_eq(2, head_a->next->content);

	mu_check(head_b == NULL);
	mu_check(push(&head_a, &head_b) == 0);

	mu_assert_int_eq(1, head_b->content);
	mu_assert_int_eq(2, head_a->content);

	mu_check(head_a->next == NULL);
	mu_check(head_b->next == NULL);

	free(head_a);
	free(head_b);
	head_a = NULL;
	head_b = NULL;
}


MU_TEST(test_push_two_number_from_a_to_b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;

	ft_lstadd_back(&head_a, ft_lstnew((void *)1));
	ft_lstadd_back(&head_a, ft_lstnew((void *)2));

	mu_assert_int_eq(1, head_a->content);
	mu_assert_int_eq(2, head_a->next->content);

	mu_check(head_b == NULL);
	mu_check(push(&head_a, &head_b) == 0);
	mu_check(push(&head_a, &head_b) == 0);

	mu_check(head_a == NULL);
	mu_assert_int_eq(2, head_b->content);
	mu_assert_int_eq(1, head_b->next->content);

	free(head_b->next);
	free(head_b);
}


MU_TEST_SUITE(test_suite_push)
{
	MU_RUN_TEST(test_push_one_number_from_a_to_b);
	MU_RUN_TEST(test_push_two_number_from_a_to_b);
}


int	main(int argc, char *argv[])
{
	MU_RUN_SUITE(test_suite_swap);
	MU_RUN_SUITE(test_suite_push);
	MU_REPORT();
	return MU_EXIT_CODE;
}
