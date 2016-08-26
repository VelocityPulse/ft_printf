#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/12 22:00:40 by                   #+#    #+#             *#
#*   Updated: 2016/08/26 01:56:33 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

LIBFTPRINTF =	../libftprintf.a
#-fsanitize=address
all: $(LIBFTPRINTF)
	gcc  maintest.c ../libftprintf.a

$(LIBFTPRINTF):
	make -C ../

clean:
	make clean -C ../

fclean:
	make fclean -C ../
	rm -f a.out

re: fclean all

r:
	@make r -C ../
	@make
	@echo "-----------------------------------------------------------------------------------"
	./a.out

b:
	gcc maintest.c blibftprintf.a
	@echo "-----------------------------------------------------------------------------------"
	./a.out

rb: r b
