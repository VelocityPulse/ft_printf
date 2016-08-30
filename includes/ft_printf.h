/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/30 16:47:21 by                  ###   ########.fr       */
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
# define _SUCCESS_			0x01

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
	t_bool	positive_sign;
	t_bool	negative_sign;
	t_bool	space;
	t_bool	zero_pad;
	t_bool	lenght_l;
	t_bool	lenght_ll;
	t_bool	lenght_h;
	t_bool	lenght_hh;
	t_bool	lenght_j;
	t_bool	lenght_z;
	t_bool	dot;
	int		dot_value;
	int		field_width;
	int		base;
	int		caps;
	void	(*fct_call)();
	char	type;
	char	fault;
	int		nb_len;
	t_bool	sign;
	int		n_field;
	int		n_dot;
}				t_specify;

typedef struct	s_data
{
	va_list		*ap;
	int			ret;
	char		*format;
	t_specify	spec;
}				t_data;

int				ft_printf(const char *format, ...);
int				process_spec(t_specify *spec, char *format);
int				select_precision(t_specify *spec, char *format, int *i);
int				select_lenght(t_specify *spec, char *format, int *i);
int				select_flags(t_specify *spec, char type);
int				select_conversion(t_specify *spec, char type);

int				sharp(t_specify *spec);

long long		va_arg_l(va_list *ap);
long long		va_arg_z(va_list *ap);
long long		va_arg_ll(va_list *ap);
long long		va_arg_hh(va_list *ap);
long long		va_arg_h(va_list *ap);

void			call_percent(t_data *data);
void			call_putnbr(t_data *data);
void			call_putnbr_l(t_data *data);
void			call_putstr(t_data *data);
void			call_putbase(t_data *data);
void			call_putbase_l(t_data *data);
void			call_putchar(t_data *data);
void			call_putpointer(t_data *data);
void			call_putwchar(t_data *data);
void			call_putwstr(t_data *data);

void			calculate_fields(t_specify *spec, int nblen, int *nd, int *nf);

void			before_printing_d(t_data *data, t_specify *spec, long long n);
void			after_printing_d(t_data *data, t_specify *spec);
void			help_putnbr(t_data *data, long long n);

void			before_printing_s(t_data *data, t_specify *spec);
void			after_printing_s(t_data *data, t_specify *spec);

void			before_printing_p(t_data *data, t_specify *spec);

#endif
