/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:04:16 by                   #+#    #+#             */
/*   Updated: 2016/08/27 04:04:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		put_sign(t_data *data, t_specify *spec, long long n)
{
	if (n >= 0)
	{
		if (spec->positive_sign == true)
			data->ret += write(1, "+", 1);
		else if (spec->space == true)
			data->ret += write(1, " ", 1);
	}
	else
		data->ret += write(1, "-", 1);
}

static void		before_printing(t_data *data, t_specify *spec, long long n)
{
	char	pad_field;

	if (spec->positive_sign == true || spec->space == true)
		spec->sign = 1;
	spec->n_dot = (spec->dot_value - spec->nb_len);
	spec->n_field = (spec->field_width - spec->nb_len) - spec->sign -
		spec->n_dot;
	if (spec->negative_sign == false)
	{
		pad_field = ' ';
		if (spec->dot == false && spec->zero_pad == true)
			pad_field = '0';
		while (--spec->n_field >= 0)
			data->ret += write(1, &pad_field, 1);
	}
	put_sign(data, spec, n);
	while (--spec->n_dot >= 0)
		data->ret += write(1, "0", 1);
}

static void		after_printing(t_data *data, t_specify *spec)
{
	if (spec->negative_sign == true)
	{
		while (--spec->n_field >= 0)
			data->ret += write(1, " ", 1);
	}
}

void			call_putnbr(t_data *data)
{
	long long	n;
	t_specify	*spec;

	spec = &data->spec;
	if (spec->lenght_h == true)
		n = va_arg_h(data->ap);
	else if (spec->lenght_hh == true)
		n = va_arg_hh(data->ap);
	else if (spec->lenght_z == true)
		n = va_arg_z(data->ap);
	else if (spec->lenght_ll == true)
		n = va_arg_ll(data->ap);
	else if (spec->lenght_l == true)
		n = va_arg_l(data->ap);
	else
		n = va_arg(*data->ap, int);
	spec->nb_len = ft_nblen_ll(n);
	data->ret += spec->nb_len;
	before_printing(data, spec, n);
	ft_putnbr_ll(n);
	after_printing(data, spec);
}

/*
** valid flags :
** h hh z ll l
*/
