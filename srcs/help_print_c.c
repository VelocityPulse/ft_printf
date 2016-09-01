/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:59:06 by                   #+#    #+#             */
/*   Updated: 2016/09/01 17:59:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	before_printing_c(t_data *data, t_specify *spec)
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

void	after_printing_c(t_data *data, t_specify *spec)
{
	if (spec->negative_sign == true)
	{
		while (--spec->n_field >= 0)
			data->ret += write(1, " ", 1);
	}
}
