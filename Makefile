NAME = push_swap
BONUS_NAME = checker

MAIN = push_swap.c

SRC =  lstnew_int.c lstlast.c  parsing.c rotate.c lst_addback.c ft_lstadd.c ft_lstlen.c push.c swap.c reverse_rotate.c sort.c update.c init.c find.c chunk.c filter.c algo.c get.c\
		convert.c 

BONUS = checker.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c


CC = gcc
CFLAGS = -Werror -Wall -Wextra -g

OBJS = $(SRC:.c=.o)
MAIN_OBJS = $(MAIN:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJS)
	@$(MAKE) -rmC ./Libft
	@$(CC) $(CFLAGS) $(MAIN) $(OBJS) ./Libft/libft.a -o $(NAME)

clean:
	@$(MAKE) -C ./Libft fclean
	@rm -rf $(OBJS)
	@rm -rf $(BONUS_OBJS)
	@rm -rf $(MAIN_OBJS)


fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)

add:
	@git add *.c
	@git add *.h
	@git add Makefile
	@git add Libft
	@git add get_next_line
	@git status

push:
	@git push origin master
	@git push intra master

bonus:$(BONUS_NAME) all

$(BONUS_NAME): $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -rmC ./Libft
	@$(CC) $(CFLAGS)  $(BONUS_OBJS) $(OBJS) ./Libft/libft.a -o $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
