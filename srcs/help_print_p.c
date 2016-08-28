/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 17:03:25 by                   #+#    #+#             */
/*   Updated: 2016/08/28 17:56:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	before_printing_p(t_data *data, t_specify *spec)
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
** 1 : after_printing_p == after_printing_d
** 2 : data->spec.n_field -= 2 is for 2 size of "0x"
*/
