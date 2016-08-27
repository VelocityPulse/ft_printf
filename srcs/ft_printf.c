/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/27 03:58:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		init_data(t_data *data, va_list *ap, char *format)
{
	data->ap = ap;
	data->format = format;
	data->ret = 0;
}

static void		init_specify(t_specify *spec)
{
	spec->sharp = false;
	spec->positive_sign = false;
	spec->negative_sign = false;
	spec->space = false;
	spec->zero_pad = false;
	spec->lenght_l = false;
	spec->lenght_ll = false;
	spec->lenght_h = false;
	spec->lenght_hh = false;
	spec->lenght_j = false;
	spec->lenght_z = false;
	spec->dot = false;
	spec->dot_value = 0;
	spec->field_width = 0;
	spec->base = 10;
	spec->caps = LO_CASE;
	spec->fct_call = NULL;
	spec->type = 0;
	spec->fault = 0;
	spec->nb_len = 0;
	spec->sign = 0;
	spec->n_field = 0;
	spec->n_dot = 0;
}

static int		parse_format(t_data *data, int *index)
{
	int		i_temp;

	i_temp = 1;
	if (data->format[*index + 1] == 0)
		return (_FAULT_);
	init_specify(&data->spec);
	i_temp += process_spec(&data->spec, &data->format[*index + 1]);
	if (data->spec.fct_call)
		data->spec.fct_call(data);
	if (data->spec.fault)
		data->ret += write(1, &data->spec.fault, 1);
	*index += i_temp;
	return (_SUCCESS_);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			index;
	t_data		data;

	index = -1;
	va_start(ap, format);
	init_data(&data, &ap, (char *)format);
	while (format[++index])
	{
		if (format[index] == '%')
			parse_format(&data, &index);
		else
		{
			ft_putchar(format[index]);
			data.ret++;
		}
	}
	va_end(ap);
	return (data.ret);
}
