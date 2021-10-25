NAME := push_swap
CFLAGS := -Wall -Werror -Wextra -g
RM := rm -rf
CC := gcc

SRC_DIR := src
OBJ_DIR := obj
LIBFT_DIR := libft
BONUS_DIR := bonus
HEADER_DIR := headers

CHECKER := checker
LIBFT := $(LIBFT_DIR)/libft.a
LIBRARY := -L$(LIBFT_DIR) -lft
HEADERS := -I$(HEADER_DIR) -I$(LIBFT_DIR)

# TEST PART
TEST := ./test
TEST_DIR := Tests
HEADERS_TEST := $(HEADERS) -I$(TEST_DIR)

SRC_TEST := $(TEST_DIR)/tests.c
OBJ_TEST := $(SRC_TEST:$(TEST_DIR)/%.c=$(OBJ_DIR)/%.o)

# MANDATORY PART
FILES_UTILS := moviment_functions.c utils_check_parser.c
FILES := main.c $(FILES_UTILS)

SRC := $(addprefix $(SRC_DIR)/,$(FILES))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_UTILS := $(addprefix $(SRC_DIR)/,$(FILES_UTILS))
OBJ_UTILS := $(SRC_UTILS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#BONUS PART
FILES_BONUS := checker.c utils_checker.c

SRC_BONUS := $(addprefix $(BONUS_DIR)/,$(FILES_BONUS))
OBJ_BONUS := $(SRC_BONUS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) -o $(NAME) $(LIBRARY)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_DIR)/push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(HEADER_DIR)/checker.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< $(HEADERS_TEST) -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

bonus: $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(HEADERS) -o $(CHECKER) $(LIBRARY)

$(TEST): $(LIBFT) $(OBJ_TEST) $(OBJ_UTILS)
	$(CC) $(OBJ_TEST) $(OBJ_UTILS) -g $(HEADERS_TEST) -o $(TEST) $(LIBRARY)
.PHONY: all clean fclean re
