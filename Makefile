#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/12 19:31:40 by                   #+#    #+#             *#
#*   Updated: 2016/08/16 01:12:01 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#



FILES =				ft_printf.c \
					select_conversion.c \
					call_putstr.c\
					call_putnbr.c \
					call_putbase.c \
					init_fct_conv.c

SRC =				$(addprefix srcs/, $(FILES))

OBJS =				$(FILES:.c=.o)

CC = 				gcc

NAME =				libftprintf.a

LIBFT =				libft/libft.a

DEBUGSEGFAULT =		-fsanitize=address

FLAGS =				#$(DEBUGSEGFAULT) #-Wextra -Werror -Wall

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
