NAME = bsp

CC     = gcc
CFLAGS = -g3 -fsanitize=address
#-Wall -Wextra -Werror 
RM     = rm -f

INC  = -Iinclude 

MAIN = main.c
SRCS = utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(MAIN) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re