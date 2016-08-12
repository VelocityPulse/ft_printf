#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/12 19:31:40 by                   #+#    #+#             *#
#*   Updated: 2016/08/12 20:20:45 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#



FILES		= ft_printf.c

SRC			= $(addprefix srcs/, $(FILES))

OBJS		= $(FILES:.c=.o)

GCC		= gcc

NAME	= libftprintf.a

LIBFT	= libft/libft.a

FLAGS	= #-Wextra -Werror -Wall

RM		= rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	mv $(LIBFT) $(NAME)
	ar r $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS):
	$(GCC) $(FLAGS) -c $(SRC)

$(LIBFT):
	make -C libft/

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all
