NAME = Push_swap

SRC = push_swap.c lstnew_int.c lstlast.c  parsing.c rotate.c lst_addback.c ft_lstadd.c ft_lstlen.c ft_countword.c push.c

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -rmC ./Libft
		gcc $(CFLAGS)  $(OBJS) ./Libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C ./Libft fclean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all