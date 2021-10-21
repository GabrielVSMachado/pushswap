#include "minunit.h"
#include "push_swap.h"

/* TEST FUNCTION SWAP */

MU_TEST(test_swap_two_integers)
{
	t_list	*head;

	head = NULL;
	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->content = (void *)0;
	head->next->content = (void *)1;

	mu_assert_int_eq(0, head->content);
	mu_assert_int_eq(1, head->next->content);

	mu_check(swap(&head) == 0);

	mu_assert_int_eq(0, head->next->content);
	mu_assert_int_eq(1, head->content);

	free(head->next);
	free(head);
	head = NULL;
}

MU_TEST(test_swap_with_one_number_and_second_null)
{
	t_list	*head;

	head = NULL;
	head = (t_list *)calloc(sizeof(t_list), 1);
	head->content = (void *)1;

	mu_assert_int_eq(1, head->content);
	mu_check(head->next == NULL);

	mu_check(swap(&head) == 1);

	mu_assert_int_eq(1, head->content);
	mu_check(head->next == NULL);

	free(head);
	head = NULL;
}

/* TESTS FOR FUNCTION PUSH*/


MU_TEST(test_push_one_number_from_a_to_b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next = (t_list *)calloc(sizeof(t_list), 1);

	head_a->content = (void *)1;
	head_a->next->content = (void *)2;

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

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next = (t_list *)calloc(sizeof(t_list), 1);

	head_a->content = (void *)1;
	head_a->next->content = (void *)2;

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

	head_a = NULL;
	head_b = NULL;
}

MU_TEST(test_push_no_number_from_a_to_b_when_a_is_NULL)
{
	t_list	*head_b;

	head_b = NULL;

	mu_check(push(NULL, &head_b) == 1);
	mu_check(head_b == NULL);
}

MU_TEST(test_push_one_number_from_a_to_b_when_b_is_NULL)
{
	t_list	*head_a;

	head_a = NULL;
	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->content = (void *)1;

	mu_check(push(&head_a, NULL) == 1);

	mu_assert_int_eq(1, head_a->content);

	free(head_a);
	head_a = NULL;
}

MU_TEST(test_push_three_numbers_from_a_to_b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head_a->content = (void *)1;
	head_a->next->content = (void *)2;
	head_a->next->next->content = (void *)3;

 	mu_assert_int_eq(1, head_a->content);
 	mu_assert_int_eq(2, head_a->next->content);
 	mu_assert_int_eq(3, head_a->next->next->content);

	mu_check(push(&head_a, &head_b) == 0);
	mu_check(push(&head_a, &head_b) == 0);
	mu_check(push(&head_a, &head_b) == 0);

 	mu_assert_int_eq(3, head_b->content);
 	mu_assert_int_eq(2, head_b->next->content);
 	mu_assert_int_eq(1, head_b->next->next->content);

 	free(head_b->next->next);
 	free(head_b->next);
	free(head_b);

	head_a = NULL;
	head_b = NULL;
}


MU_TEST(test_push_one_number_from_a_to_b_then_return_to_a)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->content = (void *)1;
	head_a->next = NULL;

	mu_assert_int_eq(1, head_a->content);
	
	mu_check(push(&head_a, &head_b) == 0);

	mu_assert_int_eq(1, head_b->content);

	mu_check(push(&head_b, &head_a) == 0);

	mu_assert_int_eq(1, head_a->content);

	mu_check(head_b == NULL);

	free(head_a);

	head_a = NULL;
	head_b = NULL;
}

MU_TEST(test_push_one_number_from_a_to_b_then_push_two_number_from_b_to_a)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_b = (t_list *)calloc(sizeof(t_list), 1);

	head_b->content = (void *)1;
	head_a->content = (void *)2;

	mu_check(push(&head_a, &head_b) == 0);

	mu_assert_int_eq(2, head_b->content);

	mu_check(push(&head_b, &head_a) == 0);

	mu_assert_int_eq(2, head_a->content);
	mu_assert_int_eq(1, head_b->content);

	mu_check(push(&head_b, &head_a) == 0);

	mu_assert_int_eq(1, head_a->content);
	mu_assert_int_eq(2, head_a->next->content);
	mu_check(head_b == NULL);

	free(head_a->next);
	free(head_a);

	head_a = NULL;
	head_b = NULL;
}

/* TESTS FOR FUNCTION ROTATE UP */

MU_TEST(test_rotate_up_the_list_the_first_become_the_last_and_vice_versa)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = (void *)1;
	head->next->content = (void *)2;
	head->next->next = NULL;

	mu_check(rotate_to_up(&head) == 0);

	mu_assert_int_eq(2, head->content);
	mu_assert_int_eq(1, head->next->content);

	mu_check(head->next->next == NULL);

	free(head->next);
	free(head);

	head = NULL;
}

MU_TEST(test_rotate_up_three_numbers)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = (void *)1;
	head->next->content = (void *)2;
	head->next->next->content = (void *)3;
	head->next->next->next = NULL;

	mu_check(rotate_to_up(&head) == 0);

	mu_assert_int_eq(2, head->content);
	mu_assert_int_eq(3, head->next->content);
	mu_assert_int_eq(1, head->next->next->content);
	
	mu_check(head->next->next->next == NULL);

	free(head->next->next);
	free(head->next);
	free(head);

	head = NULL;
}

MU_TEST(test_rotate_up_receive_NULL)
{
	mu_check(rotate_to_up(NULL) == 1);
}

MU_TEST(test_rotate_up_fifteen_numbers_one_time)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = (void *)1;
	head->next->content = (void *)2;
	head->next->next->content = (void *)3;
	head->next->next->next->content = (void *)4;
	head->next->next->next->next->content = (void *)5;
	head->next->next->next->next->next->content = (void *)6;
	head->next->next->next->next->next->next->content = (void *)7;
	head->next->next->next->next->next->next->next->content = (void *)8;
	head->next->next->next->next->next->next->next->next->content = (void *)9;
	head->next->next->next->next->next->next->next->next->next->content = (void *)10;
	head->next->next->next->next->next->next->next->next->next->next->content = (void *)11;
	head->next->next->next->next->next->next->next->next->next->next->next->content = (void *)12;
	head->next->next->next->next->next->next->next->next->next->next->next->next->content = (void *)13;
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->content = (void *)14;
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = (void *)15;

	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = NULL;

	mu_check(rotate_to_up(&head) == 0);

	mu_assert_int_eq(2, head->content);
	mu_assert_int_eq(3, head->next->content);
	mu_assert_int_eq(4, head->next->next->content);
	mu_assert_int_eq(5, head->next->next->next->content);
	mu_assert_int_eq(6, head->next->next->next->next->content);
	mu_assert_int_eq(7, head->next->next->next->next->next->content);
	mu_assert_int_eq(8, head->next->next->next->next->next->next->content);
	mu_assert_int_eq(9, head->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(10, head->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(11, head->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(12, head->next->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(13, head->next->next->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(14, head->next->next->next->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(15, head->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(1, head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);


	mu_check(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next == NULL);

	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next);
	free(head->next->next->next->next->next);
	free(head->next->next->next->next);
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);

	head = NULL;
}

MU_TEST(test_rotate_up_twice_ten_numbers)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = (void *)1;
	head->next->content = (void *)2;
	head->next->next->content = (void *)3;
	head->next->next->next->content = (void *)4;
	head->next->next->next->next->content = (void *)5;
	head->next->next->next->next->next->content = (void *)6;
	head->next->next->next->next->next->next->content = (void *)7;
	head->next->next->next->next->next->next->next->content = (void *)8;
	head->next->next->next->next->next->next->next->next->content = (void *)9;
	head->next->next->next->next->next->next->next->next->next->content = (void *)10;

	head->next->next->next->next->next->next->next->next->next->next = NULL;

	mu_check(rotate_to_up(&head) == 0);

	mu_assert_int_eq(2, head->content);
	mu_assert_int_eq(3, head->next->content);
	mu_assert_int_eq(4, head->next->next->content);
	mu_assert_int_eq(5, head->next->next->next->content);
	mu_assert_int_eq(6, head->next->next->next->next->content);
	mu_assert_int_eq(7, head->next->next->next->next->next->content);
	mu_assert_int_eq(8, head->next->next->next->next->next->next->content);
	mu_assert_int_eq(9, head->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(10, head->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(1, head->next->next->next->next->next->next->next->next->next->content);

	mu_check(head->next->next->next->next->next->next->next->next->next->next == NULL);

	mu_check(rotate_to_up(&head) == 0);

	mu_assert_int_eq(3, head->content);
	mu_assert_int_eq(4, head->next->content);
	mu_assert_int_eq(5, head->next->next->content);
	mu_assert_int_eq(6, head->next->next->next->content);
	mu_assert_int_eq(7, head->next->next->next->next->content);
	mu_assert_int_eq(8, head->next->next->next->next->next->content);
	mu_assert_int_eq(9, head->next->next->next->next->next->next->content);
	mu_assert_int_eq(10, head->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(1, head->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(2, head->next->next->next->next->next->next->next->next->next->content);

	mu_check(head->next->next->next->next->next->next->next->next->next->next == NULL);

	free(head->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next);
	free(head->next->next->next->next->next);
	free(head->next->next->next->next);
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);

	head = NULL;
}

/* Tests for function rotate_to_down */

MU_TEST(test_rotate_down_two_numbers)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = (void *)1;
	head->next->content = (void *)2;

	head->next->next = NULL;

	mu_check(rotate_to_down(&head) == 0);

	mu_assert_int_eq(2, head->content);
	mu_assert_int_eq(1, head->next->content);

	mu_check(head->next->next == NULL);

	free(head->next);
	free(head);

	head = NULL;
}


MU_TEST(test_rotate_down_three_numbers)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = (void *)1;
	head->next->content = (void *)2;
	head->next->next->content = (void *)3;

	head->next->next->next = NULL;

	mu_check(rotate_to_down(&head) == 0);

	mu_assert_int_eq(3, head->content);
	mu_assert_int_eq(1, head->next->content);
	mu_assert_int_eq(2, head->next->next->content);

	mu_check(head->next->next->next == NULL);

	free(head->next->next);
	free(head->next);
	free(head);

	head = NULL;
}

MU_TEST(test_rotate_down_fifteen_numbers)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = NULL;

	head->content = (void *)1;
	head->next->content = (void *)2;
	head->next->next->content = (void *)3;
	head->next->next->next->content = (void *)4;
	head->next->next->next->next->content = (void *)5;
	head->next->next->next->next->next->content = (void *)6;
	head->next->next->next->next->next->next->content = (void *)7;
	head->next->next->next->next->next->next->next->content = (void *)8;
	head->next->next->next->next->next->next->next->next->content = (void *)9;
	head->next->next->next->next->next->next->next->next->next->content = (void *)10;
	head->next->next->next->next->next->next->next->next->next->next->content = (void *)11;
	head->next->next->next->next->next->next->next->next->next->next->next->content = (void *)12;
	head->next->next->next->next->next->next->next->next->next->next->next->next->content = (void *)13;
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->content = (void *)14;
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = (void *)15;

	mu_check(rotate_to_down(&head) == 0);

	mu_assert_int_eq(15, head->content);
	mu_assert_int_eq(1, head->next->content);
	mu_assert_int_eq(2, head->next->next->content);
	mu_assert_int_eq(3, head->next->next->next->content);
	mu_assert_int_eq(4, head->next->next->next->next->content);
	mu_assert_int_eq(5, head->next->next->next->next->next->content);
	mu_assert_int_eq(6, head->next->next->next->next->next->next->content);
	mu_assert_int_eq(7, head->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(8, head->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(9, head->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(10, head->next->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(11, head->next->next->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(12, head->next->next->next->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(13, head->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(14, head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);

	mu_check(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next == NULL);

	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next);
	free(head->next->next->next->next->next);
	free(head->next->next->next->next);
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);

	head = NULL;
}


MU_TEST(test_rotate_down_with_parameter_NULL)
{
	mu_check(rotate_to_down(NULL) == 1);
}


MU_TEST(test_rotate_down_twice_ten_numbers)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->next->next->next->next->next->next->next->next->next->next = NULL;

	head->content = (void *)1;
	head->next->content = (void *)2;
	head->next->next->content = (void *)3;
	head->next->next->next->content = (void *)4;
	head->next->next->next->next->content = (void *)5;
	head->next->next->next->next->next->content = (void *)6;
	head->next->next->next->next->next->next->content = (void *)7;
	head->next->next->next->next->next->next->next->content = (void *)8;
	head->next->next->next->next->next->next->next->next->content = (void *)9;
	head->next->next->next->next->next->next->next->next->next->content = (void *)10;

	mu_check(rotate_to_down(&head) == 0);

	mu_assert_int_eq(10, head->content);
	mu_assert_int_eq(1, head->next->content);
	mu_assert_int_eq(2, head->next->next->content);
	mu_assert_int_eq(3, head->next->next->next->content);
	mu_assert_int_eq(4, head->next->next->next->next->content);
	mu_assert_int_eq(5, head->next->next->next->next->next->content);
	mu_assert_int_eq(6, head->next->next->next->next->next->next->content);
	mu_assert_int_eq(7, head->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(8, head->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(9, head->next->next->next->next->next->next->next->next->next->content);


	mu_check(head->next->next->next->next->next->next->next->next->next->next == NULL);

	mu_check(rotate_to_down(&head) == 0);

	mu_assert_int_eq(9, head->content);
	mu_assert_int_eq(10, head->next->content);
	mu_assert_int_eq(1, head->next->next->content);
	mu_assert_int_eq(2, head->next->next->next->content);
	mu_assert_int_eq(3, head->next->next->next->next->content);
	mu_assert_int_eq(4, head->next->next->next->next->next->content);
	mu_assert_int_eq(5, head->next->next->next->next->next->next->content);
	mu_assert_int_eq(6, head->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(7, head->next->next->next->next->next->next->next->next->content);
	mu_assert_int_eq(8, head->next->next->next->next->next->next->next->next->next->content);

	mu_check(head->next->next->next->next->next->next->next->next->next->next == NULL);

	free(head->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next);
	free(head->next->next->next->next->next);
	free(head->next->next->next->next);
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);
	
	head = NULL;
}

MU_TEST_SUITE(test_suite_swap)
{
	MU_RUN_TEST(test_swap_two_integers);
	MU_RUN_TEST(test_swap_with_one_number_and_second_null);
}


MU_TEST_SUITE(test_suite_push)
{
	MU_RUN_TEST(test_push_one_number_from_a_to_b);
	MU_RUN_TEST(test_push_two_number_from_a_to_b);
	MU_RUN_TEST(test_push_no_number_from_a_to_b_when_a_is_NULL);
	MU_RUN_TEST(test_push_three_numbers_from_a_to_b);
	MU_RUN_TEST(test_push_one_number_from_a_to_b_then_return_to_a);
	MU_RUN_TEST(test_push_one_number_from_a_to_b_then_push_two_number_from_b_to_a);
	MU_RUN_TEST(test_push_one_number_from_a_to_b_when_b_is_NULL);
}


MU_TEST_SUITE(test_suite_rotate_up)
{
	MU_RUN_TEST(test_rotate_up_the_list_the_first_become_the_last_and_vice_versa);
	MU_RUN_TEST(test_rotate_up_three_numbers);
	MU_RUN_TEST(test_rotate_up_receive_NULL);
	MU_RUN_TEST(test_rotate_up_fifteen_numbers_one_time);
	MU_RUN_TEST(test_rotate_up_twice_ten_numbers);
}


MU_TEST_SUITE(test_suite_rotate_down)
{
	MU_RUN_TEST(test_rotate_down_two_numbers);
	MU_RUN_TEST(test_rotate_down_three_numbers);
	MU_RUN_TEST(test_rotate_down_fifteen_numbers);
	MU_RUN_TEST(test_rotate_down_with_parameter_NULL);
	MU_RUN_TEST(test_rotate_down_twice_ten_numbers);
}


int	main(int argc, char *argv[])
{
	MU_RUN_SUITE(test_suite_swap);
	MU_RUN_SUITE(test_suite_push);
	MU_RUN_SUITE(test_suite_rotate_up);
	MU_RUN_SUITE(test_suite_rotate_down);
	MU_REPORT();
	return MU_EXIT_CODE;
}
