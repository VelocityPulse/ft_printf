/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 00:45:49 by                   #+#    #+#             */
/*   Updated: 2016/09/01 17:47:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			call_putwstr(t_data *data)
{
	int			*str;
	t_specify	*spec;

	spec = &data->spec;
	str = va_arg(*data->ap, int *);
	if (!str)
		str = L"(null)";
	data->spec.nb_len = ft_strwlen(str);
	if (spec->dot == true && spec->dot_value < spec->nb_len)
		spec->nb_len =  ft_strnwlen(str, spec->dot_value);
	before_printing_s(data, &data->spec);
	data->ret += ft_putnwstr(str, spec->nb_len);
	after_printing_s(data, &data->spec);
}
