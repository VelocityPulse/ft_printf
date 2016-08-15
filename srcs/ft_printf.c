/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/15 21:27:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_fct_conv(t_data *data)
{
	data->fct_conv[CONV_LO_S] = &call_putstr;
	data->fct_conv[CONV_LO_D] = &call_putnbr;
//	data->fct_conv[CONV_UP_D] = // a faire
//	data->fct_conv[CONV_LO_U] = &call_putbase;
//	data->fct_conv[CONV_UP_U] = &call_putbase_long;
/*	data->fct_conv[CONV_LO_C] = 
	data->fct_conv[CONV_LO_X] = 
	data->fct_conv[CONV_UP_X] = 
	data->fct_conv[CONV_LO_O] = 
	data->fct_conv[CONV_UP_O] = 
	data->fct_conv[CONV_UP_S] = 
	data->fct_conv[CONV_UP_C] = 
	data->fct_conv[CONV_PERCENT] = 
	data->fct_conv[CONV_P] = 
*/
}


void	init_data(t_data *data, va_list *ap, char *format)
{
	data->ap = ap;
	data->format = format;
	data->ret = 0;
	init_fct_conv(data);
}


void	init_specify(t_specify *spec)
{
	spec->sharp = 0;
}


int		parse_format(t_data *data, int *index)
{
	int		i_temp;

	i_temp = *index + 1;
	init_specify(&data->spec);
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
