/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:03:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/15 02:47:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



void	ft_init_data(t_data *data)
{
//	data->fct[CONV_LO_S] = 
/*	data->fct[CONV_LO_D] = 
	data->fct[CONV_LO_U] = 
	data->fct[CONV_UP_U] = 
	data->fct[CONV_LO_C] = 
	data->fct[CONV_LO_X] = 
	data->fct[CONV_UP_X] = 
	data->fct[CONV_LO_O] = 
	data->fct[CONV_UP_O] = 
	data->fct[CONV_UP_S] = 
	data->fct[CONV_UP_C] = 
	data->fct[CONV_PERCENT] = 
*/
}

int		parse_format(const char *format, int *index)
{
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			index;
	t_data		data;
	int			ret;

	index = -1;
	ret	 = 0;

	data.fct[2] = &ft_putstr;
	data.fct[1] = &ft_putnbr;
//	data.fct[1](1);
//	data.fct[2]("lol");

	va_start(ap, format);
	while (format[++index])
	{
		if (format[index] == '%')
			ret += parse_format(&format[index + 1], &index);
		else
		{
			ft_putchar(format[index]);
			ret++;
		}
	}
	va_end(ap);
	return (0);
}
