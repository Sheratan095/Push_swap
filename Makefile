NAME		= push_swap

COREKIT_PATH = ./Corekit

SRC = src/main.c \
	src/moves/switch.c \
	src/moves/rotate.c \

INCLUDES = ./includes

# FLAGS		= -Wall -Werror -Wextra -g
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
	@rm -fr *.o
	@rm -fr **/*.o
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
	@rm -fr mlx

test: all
	 ./$(NAME)

val: all
	 valgrind --leak-check=full --track-origins=yes -s --show-leak-kinds=all ./$(NAME)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m