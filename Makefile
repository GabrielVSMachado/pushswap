NAME := push_swap
CFLAGS := -Wall -Werror -Wextra -g
RM := rm -rf

SRC_DIR := src
OBJ_DIR := obj
LIBFT_DIR := libft
BONUS_DIR := bonus
HEADER_DIR := headers

CHECKER := checker
LIBFT := libft.a
LIBRARY := -L$(LIBFT_DIR) -lft
HEADERS := -I$(HEADER_DIR) -I$(LIBFT_DIR)

FILES := main.c
FILES_BONUS := checker.c utils_checker.c

SRC_BONUS := $(addprefix $(BONUS_DIR)/,$(FILES_BONUS))
OBJ_BONUS := $(SRC_BONUS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC := $(addprefix $(SRC_DIR)/,$(FILES))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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
.PHONY: all clean fclean re
