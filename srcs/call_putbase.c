/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 18:14:24 by                   #+#    #+#             */
/*   Updated: 2016/08/21 02:08:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putbase(t_data *data)
{
	unsigned long long	n;
	t_specify			*spec;
	char				*str;

	spec = &data->spec;
	if (spec->lenght_ll == true)
		n = va_arg_ll(data->ap);
	else if (spec->lenght_l == true)
		n = va_arg_l(data->ap);
	else if (spec->lenght_hh == true)
		n = va_arg_hh(data->ap);
	else if (spec->lenght_h == true)
		n = va_arg_h(data->ap);
	else
		n = va_arg(*data->ap, unsigned int);
	str = ft_itoa_base_ll(n, spec->base);
	if (spec->caps == LO_CASE)
		ft_lowerstr(str);
	data->ret += ft_strlen(str);
	ft_putstr(str);
	ft_memdel((void **)&str);
}
