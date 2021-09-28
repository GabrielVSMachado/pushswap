NAME := push_swap
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf
LIBFT_DIR := libft
HEADER_DIR := headers
HEADERS := -I$(HEADER_DIR) -I$(LIBFT_DIR)
LIBFT := libft.a
LIBRARY := -L$(LIBFT_DIR) -lft
SRC_DIR := src
OBJ_DIR := obj
FILES := main.c
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

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
.PHONY: all clean fclean re
