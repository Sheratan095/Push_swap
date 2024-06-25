NAME		= push_swap

COREKIT_PATH = ./Corekit

SRC = src/main.c \
	src/execution.c \
	src/sorting.c \
	src/stack_loading.c \
	src/moves.c \
	src/utils.c \
	src/moves/switch.c \
	src/moves/push.c \

# SRC = 	src/moves/switch.c \
# 	src/moves/rotate.c \
# 	src/moves/reverse_rotate.c \
# 	src/moves/push.c \

INCLUDES = ./includes

ARG = 1 3 2

FLAGS		= -Wall -Werror -Wextra -g
#TO DO rimettere le flag

OBJS		= $(SRC:%.c=%.o)

#-s used to silent terminal output
#2>/dev/null 1>/dev/null Redirect stout adnd stderr to null file and don't display them
#  -> it can be writed >/dev/null 2>&1

$(NAME): $(OBJS)
	@${MAKE} -sC $(COREKIT_PATH)
	@cc $(OBJS) $(FLAGS) -lm -L$(COREKIT_PATH) -lcorekit -o $(NAME) -s -I $(INCLUDES)
	@echo "$(GREEN)[PUSH_SWAP]:\t PROJECT COMPILED$(RESET)"

all:$(NAME)

%.o: %.c
	@cc -c $< -o $@ $(FLAGS) -I$(COREKIT_PATH)/includes -I $(INCLUDES)

#-i is used to ingore errors
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

remove_mlx:
	@rm -r mlx

test: all
	 ./$(NAME) $(ARG)

val: all
	 valgrind --leak-check=full --track-origins=yes -s --show-leak-kinds=all ./$(NAME) $(ARG)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m