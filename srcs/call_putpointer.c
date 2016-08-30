/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 19:27:12 by                   #+#    #+#             */
/*   Updated: 2016/08/30 16:49:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		before_printing_p(t_data *data, t_specify *spec)
{
	char	pad_field;
	
	pad_field = ' ';
	calculate_fields(spec, spec->nb_len, &spec->n_dot, &spec->n_field);
	data->spec.n_field -= 2;
	if (spec->negative_sign == false)
	{
		if (spec->dot == false && spec->zero_pad == true)
		{
			pad_field = '0';
			data->ret += write(1, "0x", 2);
		}
		while (--spec->n_field >= 0)
			data->ret += write(1, &pad_field, 1);
	}
	if (pad_field == ' ')
		data->ret += write(1, "0x", 2);
	while (--spec->n_dot >= 0)
		data->ret += write(1, "0", 1);
}

/*
** data->spec.n_field -= 2 is for 2 size of "0x"
*/

void			call_putpointer(t_data *data)
{
	long long	n;
	char		*str;

	n = (long long)va_arg(*data->ap, void *);
	str = ft_itoa_base_ll(n, 16);
	ft_lowerstr(str);
	data->spec.nb_len = ft_strlen(str);
	data->ret += data->spec.nb_len;
	before_printing_p(data, &data->spec);
	if (data->spec.dot == true && data->spec.dot_value == 0 && n == 0)
		data->ret--;
	else
		ft_putstr(str);
	after_printing_d(data, &data->spec);
	ft_memdel((void **)&str);
}
