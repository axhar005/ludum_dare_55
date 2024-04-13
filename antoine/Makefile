RED				=	\x1B[31m
GRN				=	\x1B[32m
YEL				=	\x1B[33m
BLU				=	\x1B[34m
MAG				=	\x1B[35m
CYN				=	\x1B[36m
WHT				=	\x1B[37m
RESET			=	\x1B[0m
CLE 			=	\e[1;1H\e[2J

NAME			=	game

#		config		#

ifeq ($(shell uname -s), Darwin)
    L = "
else
    L = '
endif


TEST = $(shell test -e raylib ; echo "$$?")

# Compiler and flags
CC				=	c++
CFLAGS			=	-Wall -Werror -Wextra -g -std=c++11 
#-fsanitize=address
RM				=	rm -f

# Sources are all .c files
SRCS	=	test.c\

#env -i ./minishell

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)
	@printf $(L)$(CYN) \n\n			correction is made by $(USER)\n\n  $(RESET)\n$(L)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o $(NAME)

mem: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt ./minishell 


# Removes objects
clean:
	@$(RM) $(OBJS)
	@printf $(L)$(GRN)clean *.o$(RESET)\n$(L)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@printf $(L)$(GRN)clean all$(RESET)\n$(L)

run: all
	@./$(NAME)

mc: all clean

re: fclean all

cp:
	cp supp.txt /tmp

.PHONY: all libft run mc 