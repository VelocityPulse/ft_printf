/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 14:45:08 by                   #+#    #+#             */
/*   Updated: 2016/08/29 18:22:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	before_printing_s(t_data *data, t_specify *spec)
{
	char	pad_field;

	spec->n_field = spec->field_width - spec->nb_len;
	if (spec->negative_sign == false)
	{
		pad_field = ' ';
		if (spec->zero_pad == true)
			pad_field = '0';
			while (--spec->n_field >= 0)
				data->ret += write(1, &pad_field, 1);
	}
}

void	after_printing_s(t_data *data, t_specify *spec)
{
	if (spec->negative_sign == true)
	{
		while (--spec->n_field >= 0)
			data->ret += write(1, " ", 1);
	}
}
