/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 19:13:18 by                   #+#    #+#             */
/*   Updated: 2016/08/30 16:47:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		before_printing_c(t_data *data, t_specify *spec)
{
	char	pad_field;

	spec->n_field = spec->field_width - 1;
	if (spec->negative_sign == false)
	{
		pad_field = ' ';
		if (spec->zero_pad == true)
			pad_field = '0';
		while (--spec->n_field >= 0)
			data->ret += write(1, &pad_field, 1);
	}
}

static void		after_printing_c(t_data *data, t_specify *spec)
{
	if (spec->negative_sign == true)
	{
		while (--spec->n_field >= 0)
			data->ret += write(1, " ", 1);
	}
}

void			call_putchar(t_data *data)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*data->ap, int);
	before_printing_c(data, &data->spec);
	data->ret += write(1, &c, 1);
	after_printing_c(data, &data->spec);
}
