SRC = ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_split.c ft_itoa.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_calloc.c ft_strnstr.c ft_atoi.c ft_memcmp.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcpy.c ft_memset.c ft_strlcat.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_tolower.c

SRCBONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

NAME = libft.a

FLAGS = -Werror -Wall -Wextra

OBJS = ${SRC:.c=.o}

OBJSBONUS = ${SRCBONUS:.c=.o}

CC = cc

%.o : %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS} ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS} ${OBJSBONUS}

bonus: ${OBJSBONUS} ${OBJS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS} ${NAME}
	
fclean: clean
		rm -f ${NAME}
re: fclean all

.PHONY: re clean all fclean
