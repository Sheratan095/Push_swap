NAME		= push_swap

COREKIT_PATH = ./corekit

SRC = src/main.c \
	src/execution.c \
	src/sorting.c \
	src/stack_loading.c \
	src/utils.c \
	src/moves/push.c \
	src/moves/switch.c \
	src/moves/rotate.c \
	src/moves/reverse_rotate.c \

INCLUDES = ./includes

ARG = 1 3 2

FLAGS		= -Wall -Werror -Wextra -g

OBJS		= $(SRC:%.c=%.o)

$(NAME): $(OBJS)
	@${MAKE} -sC $(COREKIT_PATH)
	@cc $(OBJS) $(FLAGS) -lm -L$(COREKIT_PATH) -lcorekit -o $(NAME) -s -I $(INCLUDES)
	@echo "$(GREEN)[PUSH_SWAP]:\t PROJECT COMPILED$(RESET)"

all:$(NAME)

%.o: %.c
	@cc -c $< -o $@ $(FLAGS) -I$(COREKIT_PATH)/includes -I $(INCLUDES)

clean:
	@rm -fr $(OBJS)
	@${MAKE} -C corekit clean -s
	@echo "$(RED)[COREKIT]:\t COREKIT CLEAN$(RESET)"

fclean: clean
	@rm -f *.a
	@rm -f *.out
	@rm -f *.gch
	@rm -f $(NAME)
	@${MAKE} -C corekit fclean -s
	@echo "$(RED)[COREKIT]:\t COREKIT FCLEAN$(RESET)"

re: fclean all

test: all
	 ./$(NAME) $(ARG)

val: all
	 valgrind --leak-check=full --track-origins=yes -s --show-leak-kinds=all ./$(NAME) $(ARG)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m