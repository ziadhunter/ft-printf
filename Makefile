NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
FILES = extra_utils.c  ft_printf.c  handle_char.c  handle_decimale.c  handlehexadecimale.c  handle_pointer.c  handle_string.c

OBJ =${FILES:%.c=%.o}


all: ${NAME}


$(NAME):${OBJ}
	$(AR) $@ $^

bonus: ${OBJ}
	$(AR) ${NAME} $^

test: ${OBJ}
	${CC} ${OBJ} test.c -o test

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY     : clean re all fclean bonus