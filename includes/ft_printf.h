/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/16 01:11:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "debug.h"

# include <stdarg.h>
# include "../libft/libft.h"

# define CONV_UP_S		0x1
# define CONV_UP_C		0x2
# define CONV_UP_D		0x3
# define CONV_UP_O		0x4
# define CONV_UP_X		0x5
# define CONV_UP_U		0x6

# define CONV_LO_S		0x7
# define CONV_LO_C		0x8
# define CONV_LO_D		0x9
# define CONV_LO_O		0xA
# define CONV_LO_X		0xB
# define CONV_LO_U		0xC

# define CONV_P			0xD
# define CONV_PERCENT	0xE

typedef struct	s_specify
{
	int		sharp;
}				t_specify;

typedef struct	s_data
{
	void		(*fct_conv[14])();
	va_list		*ap;
	int			ret;
	char		*format;
	t_specify	spec;
}				t_data;

void			call_putstr(t_data *data);
void			call_putnbr(t_data *data);
void			call_putbase(t_data *data, int base);

int				ft_printf(const char *format, ...);
void			init_fct_conv(t_data *data);
int				parse_conversion(t_data *data, char type);

#endif
