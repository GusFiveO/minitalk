SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memset.c ft_strlen.c ft_bzero.c \
		 ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
		 ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		 ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
		 ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_memcpy.c \
		 ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c src/buffer.c \
		 src/ft_printf_utils.c src/ft_printf.c src/parser.c src/print_arg.c \
		 src/print_arg_utils.c src/print_arg2.c src/utils.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

bonus:	${OBJS} ${BONUS_OBJS}
		ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

.c.o:
		gcc ${CFLAGS} -c $< -o $@

clean:	
		rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:		all clean fclean re bonus
