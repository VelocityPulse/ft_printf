/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/21 01:35:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "debug.h"

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define _FAULT_			0x00
# define _ERROR_			0x00
# define _SUCCES_			0x01

# define LENGHT_DEFAULT		0x00
# define LENGHT_L			0x01
# define LENGHT_LL			0x02
# define LENGHT_H			0x03
# define LENGHT_HH			0x04
# define LENGHT_J			0x05
# define LENGHT_Z			0x06

# define NO_CASE			0x00
# define LO_CASE			0x00
# define UP_CASE			0x01

typedef struct	s_specify
{
	t_bool	sharp;
	t_bool	lenght_l;
	t_bool	lenght_ll;
	t_bool	lenght_h;
	t_bool	lenght_hh;
	t_bool	lenght_j;
	t_bool	lenght_z;
	int		base;
	int		caps;
	void	(*fct_call)();
	char	type;
}				t_specify;

typedef struct	s_data
{
	va_list		*ap;
	long long	(*fct_lenght[7])();
	int			ret;
	char		*format;
	t_specify	spec;
}				t_data;

int				ft_printf(const char *format, ...);
int				select_lenght(t_data *data, t_specify *spec, char *format);
int				select_conversion(t_data *data, char type);

long long		va_arg_l(va_list *ap);
long long		va_arg_z(va_list *ap);
long long		va_arg_ll(va_list *ap);
long long		va_arg_hh(va_list *ap);
long long		va_arg_h(va_list *ap);

void			call_putnbr(t_data *data);
void			call_putnbr_l(t_data *data);
void			call_putstr(t_data *data);
void			call_putbase(t_data *data);
void			call_putbase_l(t_data *data);
void			call_putchar(t_data *data);
void			call_putpointer(t_data *data);

#endif
