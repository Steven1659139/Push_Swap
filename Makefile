NAME = push_swap

SRCS = push_swap.c lstnew_int.c lstlast.c  parsing.c rotate.c lst_addback.c ft_lstadd.c \
	ft_lstlen.c ft_countword.c push.c swap.c reverse_rotate.c sort.c update.c init.c find.c \
	filter.c make_chunk.c move_chunk.c chunk.c algo.c get.c

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g

OBJS = $(SRCS:.c=.o)

.c.o:
					${CC} ${CFLAGS}  -c $< -o ${<:.c=.o} 

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -rmC ./Libft
		gcc $(CFLAGS)  $(OBJS) ./Libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C ./Libft fclean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

add:
	git add *.c
	git add *.h
	git add Makefile

push:
	git push origin master
	git push intra master

re: fclean all