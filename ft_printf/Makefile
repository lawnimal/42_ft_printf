CC = cc
CFLAGS = -Wextra -Werror -Wall

RM = /bin/rm -f

SRCS = ft_printf.c ft_put.c ft_putchar.c

OBJS = $(SRCS:%.c=%.o)
# OBJS = $(patsubst %.c, %.o, $(SRCS))

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re