#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/12 19:31:40 by                   #+#    #+#             *#
#*   Updated: 2016/08/18 18:12:35 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#



FILES =				ft_printf.c \
					select_conversion.c \
					select_lenght.c \
					init_fct.c \
					get_lenght.c \
					call_putnbr.c \
					call_putnbr_l.c \
					call_putstr.c


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
