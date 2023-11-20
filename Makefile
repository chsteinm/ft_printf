NAME = libftprintf.a
CC = cc
CC_FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_print_conversions.c 
SRCS_U = ft_utoa.c ft_putnbr_base.c \
		ft_bzero.c ft_itoa.c ft_putchar_fd.c \
		ft_putnbr_base.c ft_putstr_fd.c ft_strdup.c \
		ft_utoa.c ft_strlen.c
OBJS = $(SRCS:.c=.o) $(addprefix utils/,$(SRCS_U:.c=.o))
HEAD = ft_printf.h
PROGRAM = prog

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
	ar rcs $(NAME) $(OBJS)

program: $(PROGRAM)

$(PROGRAM): all $(OBJS) main.c
	$(CC) $(CC_FLAGS) -o $(PROGRAM) main.c $(OBJS) -I.

%.o: %.c
	cc $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -f *.o utils/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re