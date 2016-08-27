#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/12 19:31:40 by                   #+#    #+#             *#
#*   Updated: 2016/08/27 19:47:41 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#



FILES =				ft_printf.c \
					process.c \
					select_conversion.c \
					select_lenght.c \
					select_flags.c \
					select_precision.c \
					get_lenght.c \
					call_percent.c \
					call_putnbr.c \
					call_putnbr_l.c \
					call_putstr.c \
					call_putchar.c \
					call_putbase.c \
					call_putbase_l.c \
					call_putpointer.c \
					call_putwchar.c \
					call_putwstr.c \
					sharp.c \
					help_print_d.c


SRC =				$(addprefix srcs/, $(FILES))

OBJS =				$(FILES:.c=.o)

CC = 				gcc

NAME =				libftprintf.a

LIBFT =				libft/libft.a

DEBUGSEGFAULT =		-fsanitize=address

FLAGS =				 -Wextra -Werror -Wall #$(DEBUGSEGFAULT)

RM =				rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar r $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	make -C libft/

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME) $(LIBFT)


re: fclean all

rmr:
	$(RM) $(NAME) $(OBJS)

r: rmr all
