SRCS =	ft_printf.c  ft_printf_utils.c ft_printf_utils2.c
		
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a

LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS} 
all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re