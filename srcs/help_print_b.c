/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 17:47:02 by                   #+#    #+#             */
/*   Updated: 2016/08/30 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		put_sharp_specify(t_specify *spec)
{
	if (spec->sharp_mode == SHARP_NONE)
		return (_ERROR_);
	else if (spec->sharp_mode == SHARP_HEXA_UP)
		return (write(1, "0X", 2));
	else if (spec->sharp_mode == SHARP_HEXA_LO)
		return (write(1, "0x", 2));
	else if (spec->sharp_mode == SHARP_OCTAL)
	{
		if (spec->n != 0)
			return (write(1, "0", 1));
		if (!(spec->dot == true && spec->dot_value == 0 && spec->n == 0))
			return (_ERROR_);
		return (write(1, "0", 1));

	}
	return (_ERROR_);
}

void		before_printing_b(t_data *data, t_specify *spec)
{
	char	pad_field;

	pad_field = ' ';
	calculate_fields(spec, spec->nb_len, &spec->n_dot, &spec->n_field);
	data->spec.n_field -= spec->sharp_mode;
	if (spec->negative_sign == false)
	{
		if (spec->dot == false && spec->zero_pad == true)
		{
			pad_field = '0';
			data->ret += put_sharp_specify(spec);
		}
		while (--spec->n_field >= 0)
			data->ret += write(1, &pad_field, 1);
	}
	if (pad_field == ' ')
		data->ret += put_sharp_specify(spec);
	while (--spec->n_dot >= 0)
		data->ret += write(1, "0", 1);
}