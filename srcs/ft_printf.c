/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/21 01:35:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	init_data(t_data *data, va_list *ap, char *format)
{
	data->ap = ap;
	data->format = format;
	data->ret = 0;
}


void	init_specify(t_specify *spec)
{
	spec->sharp = false;
	spec->lenght_l = false;
	spec->lenght_ll = false;
	spec->lenght_h = false;
	spec->lenght_hh = false;
	spec->lenght_j = false;
	spec->lenght_z = false;
	spec->base = 10;
	spec->caps = LO_CASE;
	spec->fct_call = NULL;
	spec->type = 0;
}

int		parse_format(t_data *data, int *index)
{
	*index = *index + 1;
	init_specify(&data->spec);
	*index += select_lenght(data, &data->spec, &data->format[*index]);
	if (data->spec.fct_call)
		data->spec.fct_call(data);
	return (0);
}

int		ft_printf(const char *format, ...)
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
