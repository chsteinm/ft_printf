NAME = libftprintf.a
CC = cc
CC_FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_print_conversions.c ft_utoa.c ft_putnbr_base.c
OBJS = $(SRCS:.c=.o)
HEAD = ft_printf.h
LIBFT_D = libft/
PROGRAM = prog

all: $(NAME)

re: fclean all

$(NAME): libft $(OBJS) $(HEAD)
	ar rcs $(NAME) $(OBJS)

libft:
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)

program: $(PROGRAM)

$(PROGRAM): all $(OBJS) main.c
	$(CC) $(CC_FLAGS) -o $(PROGRAM) main.c $(OBJS) -I ./ -I $(LIBFT_D)

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ -c $< -I ./ -I $(LIBFT_D)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

.PHONY: all clean fclean re libft