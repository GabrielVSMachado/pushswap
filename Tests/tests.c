#include "minunit.h"
#include "push_swap.h"
#define TRUE 1
#define FALSE 0

/* TEST FUNCTION SWAP */

MU_TEST(test_swap_two_integers)
{
	t_list	*head;
	int		num[2] = {0, 1};

	head = NULL;
	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->content = &num[0];
	head->next->content = &num[1];

	mu_assert_int_eq(0, *((int *)head->content));
	mu_assert_int_eq(1, *((int *)head->next->content));

	mu_check(swap(&head) == 0);

	mu_assert_int_eq(0, *((int *)head->next->content));
	mu_assert_int_eq(1, *((int *)head->content));

	free(head->next);
	free(head);
	head = NULL;
}

MU_TEST(test_swap_with_one_number_and_second_null)
{
	t_list	*head;
	int		num[1] = {1};

	head = NULL;
	head = (t_list *)calloc(sizeof(t_list), 1);
	head->content = &num;

	mu_assert_int_eq(1, *((int *)head->content));
	mu_check(head->next == NULL);

	mu_check(swap(&head) == 1);

	mu_assert_int_eq(1, *((int *)head->content));
	mu_check(head->next == NULL);

	free(head);
	head = NULL;
}


MU_TEST(test_swap_NULL)
{
	mu_check(swap(NULL) == 1);
}


MU_TEST(test_swap_pointer_which_point_to_null)
{
	t_list	*head;

	head = NULL;
	mu_check(swap(&head) == 1);
}

/* TESTS FOR FUNCTION PUSH*/


MU_TEST(test_push_one_number_from_a_to_b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		num[2] = {1, 2};

	head_a = NULL;
	head_b = NULL;

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next = (t_list *)calloc(sizeof(t_list), 1);

	head_a->content = &num[0];
	head_a->next->content = &num[1];

	mu_assert_int_eq(1, *((int *)head_a->content));
	mu_assert_int_eq(2, *((int *)head_a->next->content));

	mu_check(head_b == NULL);
	mu_check(push(&head_a, &head_b) == 0);

	mu_assert_int_eq(1, *((int *)head_b->content));
	mu_assert_int_eq(2, *((int *)head_a->content));

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
	int		num[2] = {1, 2};

	head_a = NULL;
	head_b = NULL;

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next = (t_list *)calloc(sizeof(t_list), 1);

	head_a->content = &num[0];
	head_a->next->content = &num[1];

	mu_assert_int_eq(1, *((int *)head_a->content));
	mu_assert_int_eq(2, *((int *) head_a->next->content));

	mu_check(head_b == NULL);
	mu_check(push(&head_a, &head_b) == 0);
	mu_check(push(&head_a, &head_b) == 0);

	mu_check(head_a == NULL);
	mu_assert_int_eq(2, *((int *)head_b->content));
	mu_assert_int_eq(1, *((int *)head_b->next->content));

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
	int		num = 1;

	head_a = NULL;
	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->content = &num;

	mu_check(push(&head_a, NULL) == 1);

	mu_assert_int_eq(1, *((int *)head_a->content));

	free(head_a);
	head_a = NULL;
}

MU_TEST(test_push_three_numbers_from_a_to_b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		num[3] = {1, 2, 3};

	head_a = NULL;
	head_b = NULL;

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head_a->content = &num[0];
	head_a->next->content = &num[1];
	head_a->next->next->content = &num[2];

 	mu_assert_int_eq(1, *((int *)head_a->content));
 	mu_assert_int_eq(2, *((int *)head_a->next->content));
 	mu_assert_int_eq(3, *((int *)head_a->next->next->content));

	mu_check(push(&head_a, &head_b) == 0);
	mu_check(push(&head_a, &head_b) == 0);
	mu_check(push(&head_a, &head_b) == 0);

 	mu_assert_int_eq(3, *((int *)head_b->content));
 	mu_assert_int_eq(2, *((int *)head_b->next->content));
 	mu_assert_int_eq(1, *((int *)head_b->next->next->content));

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
	int		num = 1;

	head_a = NULL;
	head_b = NULL;

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->content = &num;
	head_a->next = NULL;

	mu_assert_int_eq(1, *((int *)head_a->content));
	
	mu_check(push(&head_a, &head_b) == 0);

	mu_assert_int_eq(1, *((int *)head_b->content));

	mu_check(push(&head_b, &head_a) == 0);

	mu_assert_int_eq(1, *((int *)head_a->content));

	mu_check(head_b == NULL);

	free(head_a);

	head_a = NULL;
	head_b = NULL;
}

MU_TEST(test_push_one_number_from_a_to_b_then_push_two_number_from_b_to_a)
{
	t_list	*head_a;
	t_list	*head_b;
	int		num[2] = {1, 2};

	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_b = (t_list *)calloc(sizeof(t_list), 1);

	head_b->content = &num[0];
	head_a->content = &num[1];

	mu_check(push(&head_a, &head_b) == 0);

	mu_assert_int_eq(2, *((int *)head_b->content));

	mu_check(push(&head_b, &head_a) == 0);

	mu_assert_int_eq(2, *((int *)head_a->content));
	mu_assert_int_eq(1, *((int *)head_b->content));

	mu_check(push(&head_b, &head_a) == 0);

	mu_assert_int_eq(1, *((int *)head_a->content));
	mu_assert_int_eq(2, *((int *)head_a->next->content));
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


MU_TEST(test_rotate_up_receive_NULL_in_a_variable)
{
	t_list *head;

	head = NULL;

	mu_check(rotate_to_up(&head) == 1);
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


MU_TEST(test_rotate_down_receive_NULL_in_a_variable)
{
	t_list	*head;

	head = NULL;

	mu_check(rotate_to_down(&head) == 1);
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


/* CHECK INPUTS IF ARE DIGITS */
MU_TEST(test_check_isdigit_three_inputs_with_the_seconds_with_one_letter_btween_digits)
{
	char	*argv[3];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("134g1");
	argv[2] = ft_strdup("4");

	mu_check(check_isdigit(3, argv) == 1);

	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_three_arguments_with_spaces)
{
	char	*argv[3];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("122");
	argv[2] = ft_strdup("123 4");

	mu_check(check_isdigit(3, argv) == 1);

	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_only_digits)
{
	char	*argv[10];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("123");
	argv[2] = ft_strdup("13");
	argv[3] = ft_strdup("23");
	argv[4] = ft_strdup("12");
	argv[5] = ft_strdup("1");
	argv[6] = ft_strdup("3");
	argv[7] = ft_strdup("2");
	argv[8] = ft_strdup("103");
	argv[9] = ft_strdup("0");

	mu_check(check_isdigit(10, argv) == 0);

	free(argv[9]);
	free(argv[8]);
	free(argv[7]);
	free(argv[6]);
	free(argv[5]);
	free(argv[4]);
	free(argv[3]);
	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_null_string)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("");

	mu_check(check_isdigit(2, argv) == 1);

	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_negative_numbers)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("-2");

	mu_check(check_isdigit(2, argv) == 0);

	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_negative_between_two_numbers)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("3-2");

	mu_check(check_isdigit(2, argv) == 1);

	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_negative_numbers_and_a_letter)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("-2a");

	mu_check(check_isdigit(2, argv) == 1);

	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_minus_after_a_number)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("2-");

	mu_check(check_isdigit(2, argv) == 1);

	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_a_interrogation_symbol)
{
	char	*argv[3];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("2?3");
	argv[2] = ft_strdup("3");

	mu_check(check_isdigit(3, argv) == 1);

	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_division)
{
	char	*argv[3];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("2/3");
	argv[2] = ft_strdup("3");

	mu_check(check_isdigit(3, argv) == 1);

	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_last_chr_a_percent_symbol)
{
	char	*argv[3];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("-1233%");
	argv[2] = ft_strdup("123");

	mu_check(check_isdigit(3, argv) == 1);

	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_isdigit_with_letters_and_symbols)
{
	char	*argv[4];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("-12a33%");
	argv[2] = ft_strdup("123");
	argv[3] = ft_strdup("13");

	mu_check(check_isdigit(3, argv) == 1);

	free(argv[3]);
	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


/* TEST CHECK IF DIGIT IS GREATER THAN MAX_INT OR LESS THAN MIN_INT */
MU_TEST(test_input_digit_greater_than_int_max_and_expected_1)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("2147483648");

	mu_check(check_greater_than_max_or_less_than_min_int(2, argv) == 1);

	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_digit_is_equal_int_max_and_expected_0)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("2147483647");

	mu_check(check_greater_than_max_or_less_than_min_int(2, argv) == 0);

	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_digit_is_equal_int_min_and_expected_0)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("-2147483648");

	mu_check(check_greater_than_max_or_less_than_min_int(2, argv) == 0);

	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_digit_is_less_than_int_min_and_expected_1)
{
	char	*argv[2];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("-2147483649");

	mu_check(check_greater_than_max_or_less_than_min_int(2, argv) == 1);

	free(argv[1]);
	free(argv[0]);
}




/* TEST CHECK REPEATED ARGUMENTS */
MU_TEST(test_check_repeated_two_number_one)
{
	char	*argv[3];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("1");
	argv[2] = ft_strdup("1");

	mu_check(check_repeated(3, argv) == 1);

	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_repeated_no_repeated_numbers)
{
	char	*argv[4];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("1");
	argv[2] = ft_strdup("2");
	argv[3] = ft_strdup("3");

	mu_check(check_repeated(4, argv) == 0);

	free(argv[3]);
	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_repeated_two_fours_repeated_with_distance)
{
	char	*argv[6];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("4");
	argv[2] = ft_strdup("2");
	argv[3] = ft_strdup("3");
	argv[4] = ft_strdup("4");
	argv[5] = ft_strdup("5");

	mu_check(check_repeated(6, argv) == 1);

	free(argv[5]);
	free(argv[4]);
	free(argv[3]);
	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


MU_TEST(test_check_repeated_three_numbers_space_of_one)
{
	char	*argv[7];

	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("1");
	argv[2] = ft_strdup("2");
	argv[3] = ft_strdup("1");
	argv[4] = ft_strdup("3");
	argv[5] = ft_strdup("1");
	argv[6] = ft_strdup("4");

	mu_check(check_repeated(7, argv) == 1);

	free(argv[6]);
	free(argv[5]);
	free(argv[4]);
	free(argv[3]);
	free(argv[2]);
	free(argv[1]);
	free(argv[0]);
}


// TESTS OF FUNCTION MAKE_LLST_OF_INTS
MU_TEST(test_input_two_strings_of_numbers_and_expected_a_llst_with_two_ints)
{
	char	*numbers_as_strings[] = {"push_swap", "12", "1"};
	t_list	*head;

	head = make_llst_of_ints(3, numbers_as_strings);

	mu_assert_int_eq(12, *(int *)head->content);
	mu_assert_int_eq(1, *(int *)head->next->content);

	free(head->next->content);
	free(head->next);
	free(head->content);
	free(head);
	head = NULL;
}


MU_TEST(test_input_three_strings_of_numbers_and_expected_a_llst_with_three_ints)
{
	char	*numbers_as_strings[] = {"push_swap", "1", "2", "3"};
	t_list	*head;

	head = make_llst_of_ints(4, numbers_as_strings);

	mu_assert_int_eq(1, *(int *)head->content);
	mu_assert_int_eq(2, *(int *)head->next->content);
	mu_assert_int_eq(3, *(int *)head->next->next->content);

	mu_check(head->next->next->next == NULL);

	free(head->next->next->content);
	free(head->next->next);
	free(head->next->content);
	free(head->next);
	free(head->content);
	free(head);

	head = NULL;
}


MU_TEST(test_input_negative_numbers_as_strings_and_expect_same_as_int)
{
	char	*numbers_as_strings[] = {"push_swap", "-2", "-4", "-1"};
	t_list	*head;

	head = make_llst_of_ints(4, numbers_as_strings);

	mu_assert_int_eq(-2, head->content);
	mu_assert_int_eq(-4, head->next->content);
	mu_assert_int_eq(-1, head->next->next->content);

	free(head->next->next->content);
	free(head->next->next);
	free(head->next->content);
	free(head->next);
	free(head->content);
	free(head);

	head = NULL;
}


/* TEST FUNCTION ERROR */
MU_TEST(test_error_receive_NULL_expected_1)
{
	mu_check(_error(NULL) == 1);
}


MU_TEST(test_error_receive_stack_a_not_NULL_and_stack_b_NULL_expected_no_memory_leak_and_no_SIGSEV)
{
	t_stacks	stacks;

	stacks.stack_a = (t_list *)malloc(sizeof(t_list));
	stacks.stack_b = NULL;

	stacks.stack_a->content = malloc(sizeof(int));
	stacks.stack_a->next = NULL;
	*(int *)(stacks.stack_a->content) = 1;

	mu_check(_error(&stacks) == 1);
}


MU_TEST(test__error_receive_stack_a_not_NULL_and_stack_b_not_NULL_expected_no_memory_leak_and_no_SIGSEV)
{
	t_stacks	stacks;

	stacks.stack_a = (t_list *)malloc(sizeof(t_list));
	stacks.stack_b = (t_list *)malloc(sizeof(t_list));

	stacks.stack_a->content = malloc(sizeof(int));
	stacks.stack_b->content = malloc(sizeof(int));
	stacks.stack_a->next = NULL;
	stacks.stack_b->next = NULL;
	*(int *)(stacks.stack_a->content) = 1;
	*(int *)(stacks.stack_b->content) = 2;

	mu_check(_error(&stacks) == 1);
}

/* TEST FUNCTION CHECK_SORTED_CHUNCK IN B*/

MU_TEST(test_check_sorted_with_unsorted_lst_with_three_elements)
{
	t_list	*head;
	int		n_arr[3] = {1, 2, 3};

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = n_arr + 2;
	head->next->content = n_arr;
	head->next->next->content = n_arr + 1;

	mu_check(check_chunck_sorted_in_b(head, 3) == 0);

	free(head->next->next);
	free(head->next);
	free(head);
}


MU_TEST(test_check_sorted_with_sorted_lst_with_three_elements)
{
	t_list	*head;
	int		n_arr[3] = {1, 2, 3};

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = n_arr + 2;
	head->next->content = n_arr + 1;
	head->next->next->content = n_arr;

	mu_check(check_chunck_sorted_in_b(head, 3) == 1);

	free(head->next->next);
	free(head->next);
	free(head);
}


MU_TEST(test_check_chunk_sorted_with_one_element)
{
	t_list	*head;

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->content = malloc(sizeof(int));
	*(int *)head->content = 5;

	mu_check(check_chunck_sorted_in_b(head, 1) == 1);

	free(head->content);
	free(head);
}


/* TEST FUNCTION LESS_THAN_MID_POINT */
MU_TEST(test_list_with_two_elements_one_less_than_mid_point_expected_true)
{
	t_list	*head;
	int		nums[] = {1, 2, -1};

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = nums;
	head->next->content = nums + 1;
	head->next->next->content = nums + 2;

	mu_check(less_than_mid_point(head, 2, 1) == TRUE);

	free(head->next->next);
	free(head->next);
	free(head);
}

MU_TEST(test_with_one_number_expected_false)
{
	t_list	*head;
	int		nums[] = {1};

	head = (t_list *)calloc(sizeof(t_list), 1);

	head->content = nums;

	mu_check(less_than_mid_point(head, 1, 1) == FALSE);

	free(head);
}

MU_TEST(test_with_three_numbers_none_are_less_than_mid_point)
{
	t_list	*head;
	int		num[] = {3, 2, 4};

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = num;
	head->next->content = num + 1;
	head->next->next->content = num + 2;

	mu_check(less_than_mid_point(head, 2, 2) == FALSE);

	free(head->next->next);
	free(head->next);
	free(head);
}


/* TESTS FOR FUNCTION do_operation*/
MU_TEST(test_operation_swap_sa)
{
	t_list	*head;
	int		num[] = {1, 2};

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = num;
	head->next->content = num + 1;

	do_operation(swap, &head, "sa");

	mu_assert_int_eq(2, *(int *)head->content);
	mu_assert_int_eq(1, *(int *)head->next->content);

	free(head->next);
	free(head);
}


MU_TEST(test_operation_rotate_to_up_ra)
{
	t_list	*head;
	int		num[] = {1, 2, 3};

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = num;
	head->next->content = num + 1;
	head->next->next->content = num + 2;

	do_operation(rotate_to_up, &head, "ra");

	mu_assert_int_eq(2, *(int *)head->content);
	mu_assert_int_eq(3, *(int *)head->next->content);
	mu_assert_int_eq(1, *(int *)head->next->next->content);

	free(head->next->next);
	free(head->next);
	free(head);
}


MU_TEST(test_operation_rotate_to_down_ra)
{
	t_list	*head;
	int		num[] = {1, 2, 3};

	head = (t_list *)calloc(sizeof(t_list), 1);
	head->next = (t_list *)calloc(sizeof(t_list), 1);
	head->next->next = (t_list *)calloc(sizeof(t_list), 1);

	head->content = num;
	head->next->content = num + 1;
	head->next->next->content = num + 2;

	do_operation(rotate_to_down, &head, "rra");

	mu_assert_int_eq(3, *(int *)head->content);
	mu_assert_int_eq(1, *(int *)head->next->content);
	mu_assert_int_eq(2, *(int *)head->next->next->content);

	free(head->next->next);
	free(head->next);
	free(head);
}


/* TEST FUNCTION QUICK_SORT */
MU_TEST(test_quick_sort_twelve_numbers_decreasing_order_expected_increasing_order)
{
	int	*num;

	num = (int *)calloc(sizeof(int), 12);

	num[0] = 12;
	num[1] = 11;
	num[2] = 10;
	num[3] = 9;
	num[4] = 8;
	num[5] = 7;
	num[6] = 6;
	num[7] = 5;
	num[8] = 4;
	num[9] = 3;
	num[10] = 2;
	num[11] = 1;

	quick_sort(num, 0, 11);

	mu_assert_int_eq(1, num[0]);
	mu_assert_int_eq(2, num[1]);
	mu_assert_int_eq(3, num[2]);
	mu_assert_int_eq(4, num[3]);
	mu_assert_int_eq(5, num[4]);
	mu_assert_int_eq(6, num[5]);
	mu_assert_int_eq(7, num[6]);
	mu_assert_int_eq(8, num[7]);
	mu_assert_int_eq(9, num[8]);
	mu_assert_int_eq(10,num[9]);
	mu_assert_int_eq(11,num[10]);
	mu_assert_int_eq(12,num[11]);

	free(num);
}


MU_TEST(test_quick_sort_twelve_numbers_random_order_expected_increasing_order)
{
	int	*num;

	num = (int *)calloc(sizeof(int *), 12);

	num[0] = 8;
	num[1] = 10;
	num[2] = 11;
	num[3] = 9;
	num[4] = 7;
	num[5] = 3;
	num[6] = 6;
	num[7] = 5;
	num[8] = 4;
	num[9] = 1;
	num[10] = 2;
	num[11] = -1;

	quick_sort(num, 0, 11);

	mu_assert_int_eq(-1, num[0]);
	mu_assert_int_eq(1, num[1]);
	mu_assert_int_eq(2, num[2]);
	mu_assert_int_eq(3, num[3]);
	mu_assert_int_eq(4, num[4]);
	mu_assert_int_eq(5, num[5]);
	mu_assert_int_eq(6, num[6]);
	mu_assert_int_eq(7, num[7]);
	mu_assert_int_eq(8, num[8]);
	mu_assert_int_eq(9,num[9]);
	mu_assert_int_eq(10,num[10]);
	mu_assert_int_eq(11,num[11]);

	free(num);
}

/* TESTS TO FUNCTION TO MAKE INTS ARRAYS */
MU_TEST(test_make_a_array_with_three_numbers_expected_array_ints)
{
	int		*num;
	char	**argv;

	argv = (char **)calloc(sizeof(char *), 4);
	argv[0] = ft_strdup("push");
	argv[1] = ft_strdup("1");
	argv[2] = ft_strdup("2");
	argv[3] = ft_strdup("3");

	num = make_ints_array(4, argv);

	mu_assert_int_eq(1, num[0]);
	mu_assert_int_eq(2, num[1]);
	mu_assert_int_eq(3, num[2]);

	free(argv[0]);
	free(argv[1]);
	free(argv[2]);
	free(argv[3]);
	free(argv);
	free(num);
}


MU_TEST(test_make_a_array_with_eleven_numbers_expected_array_ints)
{
	int		*num;
	char	**argv;

	argv = (char **)calloc(sizeof(char *), 11);
	argv[0] = ft_strdup("push");
	argv[1] = ft_strdup("1");
	argv[2] = ft_strdup("2");
	argv[3] = ft_strdup("3");
	argv[4] = ft_strdup("4");
	argv[5] = ft_strdup("5");
	argv[6] = ft_strdup("6");
	argv[7] = ft_strdup("7");
	argv[8] = ft_strdup("8");
	argv[9] = ft_strdup("9");
	argv[10] = ft_strdup("10");

	num = make_ints_array(11, argv);

	mu_assert_int_eq(1, num[0]);
	mu_assert_int_eq(2, num[1]);
	mu_assert_int_eq(3, num[2]);
	mu_assert_int_eq(4, num[3]);
	mu_assert_int_eq(5, num[4]);
	mu_assert_int_eq(6, num[5]);
	mu_assert_int_eq(7, num[6]);
	mu_assert_int_eq(8, num[7]);
	mu_assert_int_eq(9, num[8]);
	mu_assert_int_eq(10, num[9]);

	free(argv[0]);
	free(argv[1]);
	free(argv[2]);
	free(argv[3]);
	free(argv[4]);
	free(argv[5]);
	free(argv[6]);
	free(argv[7]);
	free(argv[8]);
	free(argv[9]);
	free(argv[10]);
	free(argv);
	free(num);
}

/* TEST FOR FUNCTION CHUNK_LENGHT */
MU_TEST(test_array_with_seven_elements_expected_three)
{
	int	*num;

	num = (int *)calloc(sizeof(int), 7);

	num[0] = 1;
	num[1] = 2;
	num[2] = 3;
	num[3] = 4;
	num[4] = 5;
	num[5] = 6;
	num[6] = 7;

	mu_assert_int_eq(3, chunk_lenght(4, num));

	free(num);
}


MU_TEST(test_execute_the_function_twice_first_expected_3_second_2)
{
	int	*num;
	int	*tmp;
	int	len;

	num = (int*)calloc(sizeof(int), 7);

	num[0] = 1;
	num[1] = 2;
	num[2] = 3;
	num[3] = 4;
	num[4] = 5;
	num[5] = 6;
	num[6] = 7;

	len = chunk_lenght(4, num);
	mu_assert_int_eq(3, len);

	tmp = num;
	tmp += len;

	len = chunk_lenght(6, tmp);
	mu_assert_int_eq(2, len);

	free(num);
}

/*TEST PARTITION FUNCTION */
MU_TEST(test_array_with_eight_elements_expected_sending_four_to_the_other_stack)
{
	t_list	*head_a;
	t_list	*head_b;
	int		num[] = {1, 2, 3, 4, 5, 6, 7, 8};

	head_b = NULL;
	head_a = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);
	head_a->next->next->next->next->next->next->next = (t_list *)calloc(sizeof(t_list), 1);


	head_a->content = num;
	head_a->next->content = (num + 1);
	head_a->next->next->content = num + 2;
	head_a->next->next->next->content = num + 3;
	head_a->next->next->next->next->content = num + 4;
	head_a->next->next->next->next->next->content = num + 5;
	head_a->next->next->next->next->next->next->content = num + 6;
	head_a->next->next->next->next->next->next->next->content = num + 7;

	partition(&head_a, &head_b, num[4], num[0]);
	partition(&head_a, &head_b, num[6], num[0]);

	mu_assert_int_eq(7, *(int *)head_b->content);
	mu_assert_int_eq(6, *(int *)head_b->next->content);
	mu_assert_int_eq(5, *(int *)head_b->next->next->content);
	mu_assert_int_eq(4, *(int *)head_b->next->next->next->content);
	mu_assert_int_eq(3, *(int *)head_b->next->next->next->next->content);
	mu_assert_int_eq(2, *(int *)head_b->next->next->next->next->next->content);
	mu_assert_int_eq(8, *(int *)head_a->content);
	mu_assert_int_eq(1, *(int *)head_a->next->content);

	free(head_b->next->next->next->next->next);
	free(head_b->next->next->next->next);
	free(head_b->next->next->next);
	free(head_b->next->next);
	free(head_b->next);
	free(head_b);
	free(head_a->next);
	free(head_a);
}

/* TEST MAKE ARRAY OF THREE ELEMENTS */
MU_TEST(test_make_array_of_three_elements)
{
	t_list	*head;
	int		*num;

	head = calloc(sizeof(t_list), 1);
	head->next = calloc(sizeof(t_list), 1);
	head->next->next = calloc(sizeof(t_list), 1);

	head->content = calloc(sizeof(int), 1);
	head->next->content = calloc(sizeof(int), 1);
	head->next->next->content = calloc(sizeof(int), 1);

	*(int *)head->content = 5;
	*(int *)head->next->content = 3;
	*(int *)head->next->next->content = 2;

	num = make_int_array(head);

	mu_assert_int_eq(2, num[0]);
	mu_assert_int_eq(3, num[1]);
	mu_assert_int_eq(5, num[2]);

	ft_lstclear(&head, free);
	free(num);
}

MU_TEST(test_make_array_with_ten_elements)
{
	t_list	*head;
	int		*num;

	head = calloc(sizeof(t_list), 1);
	head->next = calloc(sizeof(t_list), 1);
	head->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);

	head->content = calloc(sizeof(int), 1);
	head->next->content = calloc(sizeof(int), 1);
	head->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);

	*(int *)head->content = 5;
	*(int *)head->next->content = 3;
	*(int *)head->next->next->content = 2;
	*(int *)head->next->next->next->content = 4;
	*(int *)head->next->next->next->next->content = 6;
	*(int *)head->next->next->next->next->next->content = 8;
	*(int *)head->next->next->next->next->next->next->content = 10;
	*(int *)head->next->next->next->next->next->next->next->content = 12;
	*(int *)head->next->next->next->next->next->next->next->next->content = 14;
	*(int *)head->next->next->next->next->next->next->next->next->next->content = 16;

	num = make_int_array(head);

	mu_assert_int_eq(2, num[0]);
	mu_assert_int_eq(3, num[1]);
	mu_assert_int_eq(4, num[2]);
	mu_assert_int_eq(5, num[3]);
	mu_assert_int_eq(6, num[4]);
	mu_assert_int_eq(8, num[5]);
	mu_assert_int_eq(10, num[6]);
	mu_assert_int_eq(12, num[7]);
	mu_assert_int_eq(14, num[8]);
	mu_assert_int_eq(16, num[9]);

	ft_lstclear(&head, free);
	free(num);
}

/* TEST FUNCTION FIND_ELEMENT */

MU_TEST(test_lst_with_4_elements_expected_element_next_96_prev_null)
{
	t_list	*head;
	t_list	*next;
	t_list	*prev;
	int		*ord_array;

	head = calloc(sizeof(t_list), 1);
	head->next = calloc(sizeof(t_list), 1);
	head->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next = calloc(sizeof(t_list), 1);

	head->content = calloc(sizeof(int), 1);
	head->next->content = calloc(sizeof(int), 1);
	head->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->content = calloc(sizeof(int), 1);

	*(int *)head->content = 96;
	*(int *)head->next->content = 97;
	*(int *)head->next->next->content = 98;
	*(int *)head->next->next->next->content = 99;
	ord_array = make_int_array(head);

	next = find_element(head, 94, ord_array, cmp_higher);
	prev = find_element(head, 94, ord_array, cmp_lower);

	mu_check(prev == NULL);
	mu_assert_int_eq(96, *(int *)next->content);
	mu_assert_int_eq(96, *(int *)head->content);

	free(head->next->next->next->content);
	free(head->next->next->content);
	free(head->next->content);
	free(head->content);
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);
	free(ord_array);
}

MU_TEST(test_lst_with_4_elements_expected_next_92_prev_85)
{
	t_list	*head;
	t_list	*next;
	t_list	*prev;
	int		*ord_array;

	head = calloc(sizeof(t_list), 1);
	head->next = calloc(sizeof(t_list), 1);
	head->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next = calloc(sizeof(t_list), 1);

	head->content = calloc(sizeof(int), 1);
	head->next->content = calloc(sizeof(int), 1);
	head->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->content = calloc(sizeof(int), 1);

	*(int *)head->content = 97;
	*(int *)head->next->content = 98;
	*(int *)head->next->next->content = 85;
	*(int *)head->next->next->next->content = 92;
	ord_array = make_int_array(head);

	next = find_element(head, 91, ord_array, cmp_higher);
	prev = find_element(head, 91, ord_array, cmp_lower);

	mu_assert_int_eq(92, *(int *)next->content);
	mu_assert_int_eq(85, *(int *)prev->content);
	mu_assert_int_eq(97, *(int *)head->content);

	free(head->next->next->next->content);
	free(head->next->next->content);
	free(head->next->content);
	free(head->content);
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);
	free(ord_array);
}

MU_TEST(test_lst_with_20_elements_expected_next_element_76_prev_12)
{
	t_list	*head;
	t_list	*next;
	t_list	*prev;
	int		*ord_array;

	head = calloc(sizeof(t_list), 1);
	head->next = calloc(sizeof(t_list), 1);
	head->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = calloc(sizeof(t_list), 1);

	head->content = calloc(sizeof(int), 1);
	head->next->content = calloc(sizeof(int), 1);
	head->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = calloc(sizeof(int), 1);

	*(int *)head->content = 97;
	*(int *)head->next->content = 98;
	*(int *)head->next->next->content = 99;
	*(int *)head->next->next->next->content = 92;
	*(int *)head->next->next->next->next->content = 91;
	*(int *)head->next->next->next->next->next->content = 90;
	*(int *)head->next->next->next->next->next->next->content = 89;
	*(int *)head->next->next->next->next->next->next->next->content = 12;
	*(int *)head->next->next->next->next->next->next->next->next->content = 87;
	*(int *)head->next->next->next->next->next->next->next->next->next->content = 86;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->content = 85;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->content = 84;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->next->content = 83;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->next->next->content = 82;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = 81;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = 80;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = 79;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = 78;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = 77;
	*(int *)head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content = 76;

	ord_array = make_int_array(head);
	next = find_element(head, 13, ord_array, cmp_higher);
	prev = find_element(head, 13, ord_array, cmp_lower);

	mu_assert_int_eq(12, *(int *)prev->content);
	mu_assert_int_eq(76, *(int *)next->content);
	mu_assert_int_eq(97, *(int *)head->content);

	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->next->content);
	free(head->next->next->next->next->next->content);
	free(head->next->next->next->next->content);
	free(head->next->next->next->content);
	free(head->next->next->content);
	free(head->next->content);
	free(head->content);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next);
	free(head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next);
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
	free(ord_array);
}

MU_TEST(test_lst_with_5_elements_expected_next_96_prev_94)
{
	t_list	*head;
	t_list	*next;
	t_list	*prev;
	int		*ord_array;

	head = calloc(sizeof(t_list), 1);
	head->next = calloc(sizeof(t_list), 1);
	head->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next = calloc(sizeof(t_list), 1);
	head->next->next->next->next = calloc(sizeof(t_list), 1);

	head->content = calloc(sizeof(int), 1);
	head->next->content = calloc(sizeof(int), 1);
	head->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->content = calloc(sizeof(int), 1);
	head->next->next->next->next->content = calloc(sizeof(int), 1);

	*(int *)head->content = 94;
	*(int *)head->next->content = 96;
	*(int *)head->next->next->content = 97;
	*(int *)head->next->next->next->content = 98;
	*(int *)head->next->next->next->next->content = 99;
	ord_array = make_int_array(head);

	next = find_element(head, 95, ord_array, cmp_higher);
	prev = find_element(head, 95, ord_array, cmp_lower);

	mu_assert_int_eq(96, *(int *)next->content);
	mu_assert_int_eq(94, *(int *)prev->content);
	mu_assert_int_eq(94, *(int *)head->content);

	free(head->next->next->next->next->content);
	free(head->next->next->next->content);
	free(head->next->next->content);
	free(head->next->content);
	free(head->content);
	free(head->next->next->next->next);
	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);
	free(ord_array);
}

MU_TEST_SUITE(suite_swap)
{
	MU_RUN_TEST(test_swap_two_integers);
	MU_RUN_TEST(test_swap_with_one_number_and_second_null);
	MU_RUN_TEST(test_swap_NULL);
	MU_RUN_TEST(test_swap_pointer_which_point_to_null);
}


MU_TEST_SUITE(suite_push)
{
	MU_RUN_TEST(test_push_one_number_from_a_to_b);
	MU_RUN_TEST(test_push_two_number_from_a_to_b);
	MU_RUN_TEST(test_push_no_number_from_a_to_b_when_a_is_NULL);
	MU_RUN_TEST(test_push_three_numbers_from_a_to_b);
	MU_RUN_TEST(test_push_one_number_from_a_to_b_then_return_to_a);
	MU_RUN_TEST(test_push_one_number_from_a_to_b_then_push_two_number_from_b_to_a);
	MU_RUN_TEST(test_push_one_number_from_a_to_b_when_b_is_NULL);
}


MU_TEST_SUITE(suite_rotate_up)
{
	MU_RUN_TEST(test_rotate_up_the_list_the_first_become_the_last_and_vice_versa);
	MU_RUN_TEST(test_rotate_up_three_numbers);
	MU_RUN_TEST(test_rotate_up_receive_NULL);
	MU_RUN_TEST(test_rotate_up_fifteen_numbers_one_time);
	MU_RUN_TEST(test_rotate_up_twice_ten_numbers);
	MU_RUN_TEST(test_rotate_up_receive_NULL_in_a_variable);
}


MU_TEST_SUITE(suite_rotate_down)
{
	MU_RUN_TEST(test_rotate_down_two_numbers);
	MU_RUN_TEST(test_rotate_down_three_numbers);
	MU_RUN_TEST(test_rotate_down_fifteen_numbers);
	MU_RUN_TEST(test_rotate_down_with_parameter_NULL);
	MU_RUN_TEST(test_rotate_down_twice_ten_numbers);
	MU_RUN_TEST(test_rotate_down_receive_NULL_in_a_variable);
}


MU_TEST_SUITE(suite_check_inputs)
{
	MU_RUN_TEST(test_check_isdigit_three_inputs_with_the_seconds_with_one_letter_btween_digits);
	MU_RUN_TEST(test_check_isdigit_three_arguments_with_spaces);
	MU_RUN_TEST(test_check_isdigit_with_only_digits);
	MU_RUN_TEST(test_check_isdigit_with_null_string);
	MU_RUN_TEST(test_check_isdigit_with_negative_numbers);
	MU_RUN_TEST(test_check_isdigit_with_negative_between_two_numbers);
	MU_RUN_TEST(test_check_isdigit_with_negative_numbers_and_a_letter);
	MU_RUN_TEST(test_check_isdigit_with_minus_after_a_number);
	MU_RUN_TEST(test_check_isdigit_with_a_interrogation_symbol);
	MU_RUN_TEST(test_check_isdigit_with_division);
	MU_RUN_TEST(test_check_isdigit_with_last_chr_a_percent_symbol);
	MU_RUN_TEST(test_check_isdigit_with_letters_and_symbols);
}

MU_TEST_SUITE(suite_check_greater_than_max_or_less_than_min_int)
{
	MU_RUN_TEST(test_input_digit_greater_than_int_max_and_expected_1);
	MU_RUN_TEST(test_digit_is_equal_int_max_and_expected_0);
	MU_RUN_TEST(test_digit_is_equal_int_min_and_expected_0);
	MU_RUN_TEST(test_digit_is_less_than_int_min_and_expected_1);
}


MU_TEST_SUITE(suite_check_repeated)
{
	MU_RUN_TEST(test_check_repeated_two_number_one);
	MU_RUN_TEST(test_check_repeated_no_repeated_numbers);
	MU_RUN_TEST(test_check_repeated_two_fours_repeated_with_distance);
	MU_RUN_TEST(test_check_repeated_three_numbers_space_of_one);
}


MU_TEST_SUITE(suite_make_lst_with_ints)
{
	MU_RUN_TEST(test_input_two_strings_of_numbers_and_expected_a_llst_with_two_ints);
	MU_RUN_TEST(test_input_three_strings_of_numbers_and_expected_a_llst_with_three_ints);
}


MU_TEST_SUITE(suite_error)
{
	MU_RUN_TEST(test_error_receive_NULL_expected_1);
	MU_RUN_TEST(test_error_receive_stack_a_not_NULL_and_stack_b_NULL_expected_no_memory_leak_and_no_SIGSEV);
	MU_RUN_TEST(test__error_receive_stack_a_not_NULL_and_stack_b_not_NULL_expected_no_memory_leak_and_no_SIGSEV);
}

MU_TEST_SUITE(suite_check_sorted)
{
	MU_RUN_TEST(test_check_sorted_with_unsorted_lst_with_three_elements);
	MU_RUN_TEST(test_check_sorted_with_sorted_lst_with_three_elements);
	MU_RUN_TEST(test_check_chunk_sorted_with_one_element);
}


MU_TEST_SUITE(suite_less_than_mid_point)
{
	MU_RUN_TEST(test_list_with_two_elements_one_less_than_mid_point_expected_true);
	MU_RUN_TEST(test_with_one_number_expected_false);
	MU_RUN_TEST(test_with_three_numbers_none_are_less_than_mid_point);
}


MU_TEST_SUITE(suite_do_operation)
{
	MU_RUN_TEST(test_operation_swap_sa);
	MU_RUN_TEST(test_operation_rotate_to_up_ra);
	MU_RUN_TEST(test_operation_rotate_to_down_ra);
}

MU_TEST_SUITE(suite_quick_sort)
{
	MU_RUN_TEST(test_quick_sort_twelve_numbers_decreasing_order_expected_increasing_order);
	MU_RUN_TEST(test_quick_sort_twelve_numbers_random_order_expected_increasing_order);
}

MU_TEST_SUITE(suite_make_int_array)
{
	MU_RUN_TEST(test_make_a_array_with_three_numbers_expected_array_ints);
	MU_RUN_TEST(test_make_a_array_with_eleven_numbers_expected_array_ints);
}

MU_TEST_SUITE(suite_chunk_lenght)
{
	MU_RUN_TEST(test_array_with_seven_elements_expected_three);
	MU_RUN_TEST(test_execute_the_function_twice_first_expected_3_second_2);
}

MU_TEST_SUITE(suite_partition)
{
	MU_RUN_TEST(test_array_with_eight_elements_expected_sending_four_to_the_other_stack);
}

MU_TEST_SUITE(suite_make_array_ints_from_llst)
{
	MU_RUN_TEST(test_make_array_of_three_elements);
	MU_RUN_TEST(test_make_array_with_ten_elements);
}

MU_TEST_SUITE(suite_find_element)
{
	MU_RUN_TEST(test_lst_with_4_elements_expected_element_next_96_prev_null);
	MU_RUN_TEST(test_lst_with_4_elements_expected_next_92_prev_85);
	MU_RUN_TEST(test_lst_with_20_elements_expected_next_element_76_prev_12);
	MU_RUN_TEST(test_lst_with_5_elements_expected_next_96_prev_94);
}

int	main(int argc, char *argv[])
{
	MU_RUN_SUITE(suite_swap);
	MU_RUN_SUITE(suite_push);
	MU_RUN_SUITE(suite_rotate_up);
	MU_RUN_SUITE(suite_rotate_down);
	MU_RUN_SUITE(suite_check_inputs);
	MU_RUN_SUITE(suite_check_repeated);
	MU_RUN_SUITE(suite_make_lst_with_ints);
	MU_RUN_SUITE(suite_check_greater_than_max_or_less_than_min_int);
	MU_RUN_SUITE(suite_error);
	MU_RUN_SUITE(suite_check_sorted);
	MU_RUN_SUITE(suite_less_than_mid_point);
	/* MU_RUN_SUITE(suite_do_operation); */
	MU_RUN_SUITE(suite_quick_sort);
	MU_RUN_SUITE(suite_make_int_array);
	MU_RUN_SUITE(suite_chunk_lenght);
	/* MU_RUN_SUITE(suite_partition); */
	MU_RUN_SUITE(suite_make_array_ints_from_llst);
	MU_RUN_SUITE(suite_find_element);
	MU_REPORT();
	return MU_EXIT_CODE;
}
