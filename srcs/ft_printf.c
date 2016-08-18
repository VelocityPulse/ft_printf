/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/18 18:09:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	init_data(t_data *data, va_list *ap, char *format)
{
	data->ap = ap;
	data->format = format;
	data->ret = 0;
	init_fct_lenght(data);
}


void	init_specify(t_specify *spec)
{
	spec->sharp = 0;
	spec->lenght = LENGHT_DEFAULT;
}

int		parse_format(t_data *data, int *index)
{
	int		i_temp;

	i_temp = *index + 1;
	init_specify(&data->spec);
	i_temp = select_lenght(&data->spec, &data->format[i_temp]);
	if (parse_conversion(data, data->format[i_temp]))
		*index = i_temp;
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
