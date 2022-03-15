NAME = Push_swap

SRC = push_swap.c lstnew_int.c lstlast.c  parsing.c rotate.c lst_addback.c ft_lstadd.c ft_lstlen.c

FLAG = -Werror -Wall -Wextra

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -rmC ./Libft
		gcc  $(OBJS) $(FLAG) ./Libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C ./Libft fclean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all