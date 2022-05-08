NAME = libft.a

SRC =  ft_strlen.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_tolower.c \
	  ft_isalpha.c ft_isascii.c ft_toupper.c ft_atoi.c ft_strncmp.c ft_memset.c \
	  ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strchr.c \
	  ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strtrim.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c ft_strmapi.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_abs.c ft_lstprint.c ft_yo_its_wrong.c\

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c 
# ft_lstmap.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

HDRS = libft.h

all: $(NAME)

$(NAME): 
	@gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC) $(BONUS)
	@ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	@ranlib $(NAME)

bonus:
	@gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC) $(BONUS)
	@ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -rf $(NAME) $(OBJS_BONUS)

re: fclean all
